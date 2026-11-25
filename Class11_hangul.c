#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Class11_hangul.h"

int read_hangul(char *filename, HAN *list[], int count, int capacity) {
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

int count_freq(char *han, HAN *list[], int count, int capacity) {
    for (int i = 0; i < count; i++) {
        if (strcmp(han, list[i]->w) == 0) {
            list[i]->freq++;
            return count;
        }
    }

    if (count >= capacity) {
        fprintf(stderr, "Error: Hangul table capacity (%d) exceeded\n", capacity);
        exit(EXIT_FAILURE);
    }
    list[count] = allocate_han(han);
    return count + 1;
}

HAN *allocate_han(char *han) {
    HAN *entry = (HAN *)malloc(sizeof(HAN));
    if (entry == NULL) {
        fprintf(stderr, "Error: unable to allocate Hangul entry\n");
        exit(EXIT_FAILURE);
    }

    size_t length = strlen(han) + 1;
    entry->w = (char *)malloc(length);
    if (entry->w == NULL) {
        free(entry);
        fprintf(stderr, "Error: unable to allocate Hangul character\n");
        exit(EXIT_FAILURE);
    }
    memcpy(entry->w, han, length);
    entry->freq = 1;
    return entry;
}

void print_hans(HAN *list[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", list[i]->w, list[i]->freq);
    }
    printf("\n");
}

int compare_by_han(const void *a, const void *b) {
    const HAN *han_a = *(HAN * const *)a;
    const HAN *han_b = *(HAN * const *)b;
    return strcmp(han_a->w, han_b->w);
}
