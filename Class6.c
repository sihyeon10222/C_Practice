#include <stdio.h>

#define SIZE1 4
#define SIZE2 5
#define SIZE3 9

int my_strlen(char str[]);
void get_types(char *c, int *i, float *f);
double * get_max(double A[], int size);
int merge(int AA[], int s1, int BB[], int s2, int CC[], int s3);

int main() {
    //11장 연습문제 4번
    int len = my_strlen("Hello World");
    printf("Hello World의 길이 = %d\n", len);

    //11장 연습문제 5번
    char c;
    int i;
    float f;
    get_types(&c, &i, &f);
    printf("%c, %d, %f\n", c, i, f);

    //11장 연습문제 8번
    double A[] = {1.23, 3.13, 9.16, 100.90};
    int size = sizeof(A)/sizeof(A[0]);
    double * pd = get_max(A, size);
    printf("최대값 = %f\n", *pd);

    //11장 연습문제 16번
    int AA[SIZE1] = {2, 5, 7, 8};
    int BB[SIZE2] = {1, 3, 4, 6, 7};
    int CC[SIZE3]; //1, 2, 3, 4, 5, 6, 7, 7, 8
    int num = merge(AA, SIZE1, BB, SIZE2, CC, SIZE3);
    for (int i = 0; i < num; i++)
        printf("%d", CC[i]);
    printf("\n");
}

//배열 정렬기
int merge(int *AA, int s1, int *BB, int s2, int *CC, int s3) {

}

//문자열의 길이를 구한다.
int my_strlen(char str[]) {
    char* p = str;
    while (*p != '\0')
        p++;
    return p - str;
}

//문자열 배열에 여러 자료형을 쓰고 읽는다.
void get_types(char *c, int *i, float *f) {
    char buf[BUFSIZ];
    //문자열에 여러 자료형을 쓰기
    char *pc = &buf[0];     *pc = 'a';
    int *pi = &buf[1];      *pi = 100;
    float *pf = &buf[5];    *pf = 3.14F;
    //읽기
    *c = *pc;
    *i = *pi;
    *f = *pf;
}

//최대값이 들어있는 원소의 주소를 구한다.
double *get_max(double A[], int size) {
    double *max = &A[0];
    for (int i = 1; i < size; i++)
        if (*max < A[i])
            max = &A[i];
    return max;
}