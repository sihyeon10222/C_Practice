#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#include "Class10_hangul.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file1 file2...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    HAN* list[N_HAN];
    int count = 0;
    for (int i = 1; i < argc; i++) {
        count = read_hangul(argv[i], list, count, N_HAN);
    }
    print_hans(list, count);
    qsort(list, count, sizeof(HAN*), compare_by_han);
    print_hans(list, count);
    return 0;
}

int count_freq(char *han, HAN *list[], int count, int capacity) {
    for (int i = 0; i < count; i++) {
        if (strcmp(han, list[i]->w) == 0) {
            list[i]->freq++;
            return count;
        }
    }
    list[count] = allocate_han(han);
    return count + 1;
}

HAN* allocate_han(char *han) {
    HAN* n = (HAN*)malloc(sizeof(HAN));
    n->w = strdup(han);
    n->freq = 1;
    return n;
}

void print_hans(HAN *list[], int count) {
    for (int i = 0; i < count; i++)
        printf("%s: %d\n", list[i]->w, list[i]->freq);
    printf("\n\n\n");
}

int compare_by_han(const void *a, const void *b) {
    const HAN *han_a = *(HAN * const *)a;
    const HAN *han_b = *(HAN * const *)b;
    return strcmp(han_a->w, han_b->w);
}
