#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define BUFSIZE 1024

int main() {
    const char* filename = "../news.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "파일(%s)을 열 수 없습니다.\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZE];
    const char *delimit = " \n\t.,;:";

    int linecount = 0;
    int wordcount = 0;
    int uniqueWords = 0;

    char words[1000][BUFSIZE];   // 서로 다른 단어를 최대 1000개 저장
    int counts[1000] = {0};     // 모든 칸 0으로 초기화

    while (fgets(buffer, BUFSIZE, fp) != NULL)  {
        printf("%s", buffer);
        char *w = strtok(buffer,  delimit);
        while (w != NULL) {
            printf("%s\n", w);
            wordcount++;

            // 이미 저장된 단어인지 찾기
            int i;
            for (i = 0; i < uniqueWords; i++) {
                if (strcmp(words[i], w) == 0) {
                    break;
                }
            }

            // 처음 나온 단어이면 배열에 저장
            if (i == uniqueWords) {
                if (uniqueWords == 1000) {
                    fprintf(stderr, "서로 다른 단어는 1000개까지 저장할 수 있습니다.\n");
                    fclose(fp);
                    exit(EXIT_FAILURE);
                }
                strcpy(words[i], w);
                uniqueWords++;
            }
            counts[i]++;

            w = strtok(NULL, delimit);
        }
        linecount++;
    }

    // 뒤에 더 많이 나온 단어가 있으면 단어와 횟수를 함께 교환
    for (int i = 0; i < uniqueWords - 1; i++) {
        for (int j = i + 1; j < uniqueWords; j++) {
            if (counts[i] < counts[j]) {
                int tempCount = counts[i];
                counts[i] = counts[j];
                counts[j] = tempCount;

                char tempWord[BUFSIZE];
                strcpy(tempWord, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tempWord);
            }
        }
    }


    printf("줄 수: %d\n", linecount);
    printf("단어 수: %d\n", wordcount);
    printf("단어별 빈도 수 (많은 순):\n");
    for (int i = 0; i < uniqueWords; i++) {
        printf("%s %d개\n", words[i], counts[i]);
    }

    fclose(fp);
    return 0;
}
