#ifndef C_PRACTICE_CLASS11_HANGUL_H
#define C_PRACTICE_CLASS11_HANGUL_H

#define N_HAN 10000

typedef struct hangul {
    char *w;
    int freq;
} HAN;

int read_hangul(char *filename, HAN *list[], int count, int capacity);
int count_freq(char *han, HAN *list[], int count, int capacity);
HAN *allocate_han(char *han);
void print_hans(HAN *list[], int count);
int compare_by_han(const void *first, const void *second);

#endif
