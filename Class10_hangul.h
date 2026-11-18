#ifndef __HANGUL__
#define __HANGUL__
#define N_HAN 10000

struct hangul {
    char *w;
    int freq;
};
typedef struct hangul HAN;
int read_hangul(char *filename, HAN *list[], int count, int capacity);
int count_freq(char *han, HAN *list[], int count, int capacity);
HAN *allocate_han(char *han);
void print_hans(HAN *list[], int count);
int compare_by_han(const void *a, const void *b);

#endif