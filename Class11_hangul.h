#ifndef C_PRACTICE_CLASS11_HANGUL_H
#define C_PRACTICE_CLASS11_HANGUL_H

#include <stdio.h>

#define N_HAN 10000

typedef struct hangul {
    char w[5];
    int freq;
} HAN;

int read_hangul(char *filename, HAN list[], int count, int capacity);
int count_freq(char *han, HAN list[], int count, int capacity);
void print_hans(HAN list[], int count);
int compare_by_han(const void *first, const void *second);
HAN binary_search_from_file(FILE *fp, const char *word);

#endif
