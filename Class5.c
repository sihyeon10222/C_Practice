/*
실습 #1 다음과 같이 30명의 점수를 저장할 배열을 선언한다.
#define N_STUDENTS 30
int scores[N_STUDENTS];

30명의 점수는 0~100사이의 난수를 이용해서 초기하하여 다음 기능을 수행하는 프로그램을 작성하시오. 단 가능한 한 모든 기능은 함수로 작성되어야 하며 최소한 6개 이상의 함수가 포함되어야 합니다.
1. 전체 학생의 점수를 출력한다.
2. 최고 점수와 최저 점수를 구한다.
3. 전체 학생의 평균 점수를 구한다.
4. 다음과 같은 식으로 전체 학생의 표준 편차를 구한다. 여기서 m은 평균이다.
5. 평균 이상의 점수를 받은 학생 수를 구한다.
6. 점수 구간별 학생 수를 다음과 같이 출력한다.
90~100점
80~89점
70~79점
60~69점
0~59점
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N_STUDENTS 30

double get_Avg(void);
void print_scores(void);
int Max(void);
int Min(void);
double StDev(double Avg);
int CountAboveAvg(double Avg);
void print_Distribution(void);

int scores[N_STUDENTS];

int main(void) {

    srand(time(NULL));
    int i;
    for (i = 0; i < N_STUDENTS; i++) {
        scores[i] = rand() % 101;
    }

    double Avg;
    Avg = get_Avg();

    printf("<전체 학생의 점수>\n");
    print_scores();
    printf("\n최고 점수: %d점\n", Max());
    printf("\n최저 점수: %d점\n", Min());
    printf("\n전체 학생의 평균 점수: %f점\n", Avg);
    printf("\n전체 학생의 표준 편차: %f점\n", StDev(Avg));
    printf("\n평균 이상의 점수를 받은 학생 수: %d명\n", CountAboveAvg(Avg));
    printf("\n<점수 구간별 학생 수>\n");
    print_Distribution();

    return 0;
}

double get_Avg(void) {
    int i;
    double sum = 0;
    for (i = 0; i < N_STUDENTS; i++) {
        sum += scores[i];
    }
    return sum / N_STUDENTS;
}

void print_scores(void) {
    int i;
    for (i = 0; i < N_STUDENTS; i++)
        printf("학생 %d: %d점\n", i+1, scores[i]);
}

int Max(void) {
    int i;
    int max = scores[0];
    for (i = 1; i < N_STUDENTS; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

int Min(void) {
    int i;
    int min = scores[0];
    for (i = 1; i < N_STUDENTS; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    return min;
}

double StDev(double Avg) {
    double sum = 0;

    int i;
    for (i = 0; i < N_STUDENTS; i++) {
        sum += (scores[i] - Avg) * (scores[i] - Avg);
    }
    return sqrt(sum / N_STUDENTS);
}

int CountAboveAvg(double Avg) {
    int number = 0;

    int i;
    for (i = 0; i < N_STUDENTS; i++) {
        if (scores[i] >= Avg)
            number++;
    }
    return number;
}

void print_Distribution(void)
{
    int count[5] = {0};

    int i;
    for (i = 0; i < N_STUDENTS; i++) {
        if (scores[i] >= 90)
            count[0]++;
        else if (scores[i] >= 80)
            count[1]++;
        else if (scores[i] >= 70)
            count[2]++;
        else if (scores[i] >= 60)
            count[3]++;
        else
            count[4]++;
    }
    printf("90~100점: %d명\n", count[0]);
    printf("80~89점: %d명\n", count[1]);
    printf("70~79점: %d명\n", count[2]);
    printf("60~69점: %d명\n", count[3]);
    printf("0~59점: %d명\n", count[4]);
}