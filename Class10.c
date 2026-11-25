#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Class10_hangul.h"

static int compare_han_key(const void *key, const void *element) {
    const char *word = (const char *)key;
    const HAN *han = *(HAN * const *)element;
    return strcmp(word, han->w);
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

    char input[5];
    while (1) {
        printf("한글 한 글자 입력> ");
        if (scanf("%4s", input) != 1) break;

        HAN **result = bsearch(input, list, (size_t)count,
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
