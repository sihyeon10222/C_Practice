#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#include "Class10_hangul.h"

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
            //printf("%s\n", han);
            count = count_freq(han, list, count, capacity);
        }
    }
    fclose(fp);
    return count;
}
