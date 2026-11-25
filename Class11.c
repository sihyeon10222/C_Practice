#include <stdio.h>
#include <stdlib.h>

#include "Class11_hangul.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s 파일1 파일2 ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    HAN list[N_HAN] = {0};
    int count = 0;
    for (int i = 1; i < argc; i++) {
        count = read_hangul(argv[i], list, count, N_HAN);
    }

    qsort(list, (size_t)count, sizeof(HAN), compare_by_han);

    {
        FILE* fp = fopen("bin.bin", "wb");
        fwrite(list, sizeof(HAN), count, fp);
        fclose(fp);
    }

    FILE* fp = fopen("bin.bin", "rb");
    HAN nlist[N_HAN];
    fread(nlist, sizeof(HAN), count, fp);
    print_hans(nlist, count);

    HAN han = binary_search_from_file(fp, "가");
    printf("%s(%d)\n", han.w, han.freq);
    fclose(fp);
    return 0;
}
