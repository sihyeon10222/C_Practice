#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Class11_hangul.h"

int read_hangul(char *filename, HAN list[], int count, int capacity) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char buf[BUFSIZ];
    char han[5];
    while (fgets(buf, BUFSIZ, fp) != NULL) {
        size_t len = strlen(buf);
        for (size_t i = 0; i < len; i++) {
            unsigned char lead = (unsigned char)buf[i];
            size_t char_len;

            if (lead < 0x80) continue;
            if ((lead & 0xE0) == 0xC0) char_len = 2;
            else if ((lead & 0xF0) == 0xE0) char_len = 3;
            else if ((lead & 0xF8) == 0xF0) char_len = 4;
            else continue;

            if (i + char_len > len) break;
            memcpy(han, &buf[i], char_len);
            han[char_len] = '\0';
            i += char_len - 1;
            count = count_freq(han, list, count, capacity);
        }
    }
    fclose(fp);
    return count;
}

int count_freq(char *han, HAN list[], int count, int capacity) {
    for (int i = 0; i < count; i++) {
        if (strcmp(han, list[i].w) == 0) {
            list[i].freq++;
            return count;
        }
    }

    if (count >= capacity) {
        fprintf(stderr, "Error: Hangul table capacity (%d) exceeded\n", capacity);
        exit(EXIT_FAILURE);
    }
    strcpy(list[count].w, han);
    list[count].freq = 1;
    return count + 1;
}

void print_hans(HAN list[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", list[i].w, list[i].freq);
    }
    printf("\n");
}

int compare_by_han(const void *a, const void *b) {
    const HAN *han_a = a;
    const HAN *han_b = b;
    return strcmp(han_a->w, han_b->w);
}

HAN binary_search_from_file(FILE *fp, const char *word) {
    if (fseek(fp, 0, SEEK_END) != 0) {
        perror("bin.bin");
        exit(EXIT_FAILURE);
    }
    long size = ftell(fp);
    if (size < 0) {
        perror("bin.bin");
        exit(EXIT_FAILURE);
    }

    long record_size = (long)sizeof(HAN);
    long left = 0;
    long right = size / record_size - 1;
    while (left <= right) {
        long mid = left + (right - left) / 2;
        HAN han;
        if (fseek(fp, mid * record_size, SEEK_SET) != 0 ||
            fread(&han, sizeof(HAN), 1, fp) != 1) {
            fprintf(stderr, "bin.bin에서 빈도표를 읽을 수 없습니다.\n");
            exit(EXIT_FAILURE);
        }

        int comparison = strcmp(word, han.w);
        if (comparison == 0) return han;
        if (comparison < 0) right = mid - 1;
        else left = mid + 1;
    }

    HAN not_found = {0};
    snprintf(not_found.w, sizeof(not_found.w), "%s", word);
    return not_found;
}
