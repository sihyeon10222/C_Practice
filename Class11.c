#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Class11_hangul.h"

static int compare_han_key(const void *key, const void *element) {
    const char *word = (const char *)key;
    const HAN *han = *(HAN * const *)element;
    return strcmp(word, han->w);
}

static int is_single_utf8_character(const char *text, size_t length) {
    if (length == 0) return 0;

    const unsigned char *bytes = (const unsigned char *)text;
    size_t char_length;
    if (bytes[0] <= 0x7F) char_length = 1;
    else if (bytes[0] >= 0xC2 && bytes[0] <= 0xDF) char_length = 2;
    else if (bytes[0] >= 0xE0 && bytes[0] <= 0xEF) char_length = 3;
    else if (bytes[0] >= 0xF0 && bytes[0] <= 0xF4) char_length = 4;
    else return 0;

    if (length != char_length) return 0;
    for (size_t i = 1; i < char_length; i++) {
        if ((bytes[i] & 0xC0) != 0x80) return 0;
    }

    /* Reject overlong encodings, UTF-16 surrogates, and values above U+10FFFF. */
    if (char_length == 3 &&
        ((bytes[0] == 0xE0 && bytes[1] < 0xA0) ||
         (bytes[0] == 0xED && bytes[1] >= 0xA0))) return 0;
    if (char_length == 4 &&
        ((bytes[0] == 0xF0 && bytes[1] < 0x90) ||
         (bytes[0] == 0xF4 && bytes[1] > 0x8F))) return 0;

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s 파일1 파일2 ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    HAN *list[N_HAN];
    int count = 0;
    for (int i = 1; i < argc; i++) {
        count = read_hangul(argv[i], list, count, N_HAN);
    }

    qsort(list, (size_t)count, sizeof(list[0]), compare_by_han);
    print_hans(list, count);

    char input[BUFSIZ];
    while (1) {
        printf("한글 한 글자 입력 (q 입력 시 종료)> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) break;

        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[--length] = '\0';
        } else if (!feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Discard the rest of an overlong input line. */
            }
            printf("한 글자만 입력하세요.\n");
            continue;
        }

        if (length > 0 && input[length - 1] == '\r') {
            input[--length] = '\0';
        }
        if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) break;

        if (!is_single_utf8_character(input, length)) {
            printf("UTF-8 한 글자만 입력하세요.\n");
            continue;
        }

        HAN **result = (HAN **)bsearch(input, list, (size_t)count,
                                       sizeof(list[0]), compare_han_key);
        if (result != NULL) {
            printf("%s: %d\n", (*result)->w, (*result)->freq);
        } else {
            printf("찾을 수 없습니다.\n");
        }
    }

    for (int i = 0; i < count; i++) {
        free(list[i]->w);
        free(list[i]);
    }
    return 0;
}
