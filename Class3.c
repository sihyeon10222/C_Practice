#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <tgmath.h>


#define NO_ROOT 0
#define YES_ROOT 1

int compute_roots(double a, double b, double c, double *x1, double *x2);
int calculator(int x, int y, char op);
int computer_gcd(int a1, int b1);
double compute_pi(int loop_count);
double compute_pi2(int loop_count);
double random_real();
double distance(double x, double y);



int main() {
    srand(time(NULL));

    // lab 이차방정식 ax^2 + bx + c
    double a=1.0, b=2.0, c=1.0;
    double x1, x2;
    int flag = compute_roots(a, b, c, &x1, &x2);
    if (flag == YES_ROOT)
        printf("(%f, %f, %f) = %f, %f\n", a, b, c, x1, x2);
    else
        printf("근을 구할 수 없습니다.\n");

    // lab 간단한 산술 계산기
    int x = 10, y = 5;
    char op = '+';
    int res = calculator(x, y, op);
    printf("%d %c %d = %d\n", x, op, y, res);

    // lab 최대공약수
    int a1 = 12.0, b1 = 6.0;
    int gcd = computer_gcd(a1, b1);
    printf("(%d %d) => %d\n", a1, b1, gcd);

    // lab 파이 구하기
    double pi = compute_pi(100000000);
    printf("파이 = %f\n", pi);

    // 연습분제 7-19
    double pi2 = compute_pi2(100000000);
    printf("파이 = %f\n", pi2);


    return 0;
}



// 이차방정식의 근을 구한다.
int compute_roots(double a, double b, double c, double* x1, double* x2) {
    if (fabs(a - 0.0) < 1.E-10)
        return (NO_ROOT);
    double dis = pow(b, 2.0) - 4.0*a*c;
    if (dis < 0)
        return (NO_ROOT);
    *x1 = (-b + sqrt(dis)) / (2.0*a);
    *x2 = (-b - sqrt(dis)) / (2.0*a);
    return YES_ROOT;
}

// 간단한 산술 계산기
// 연산자: + - * / %
int calculator(int x, int y, char op) {
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/':
            if (y == 0) {
            fprintf(stderr, "0으로는 나눌 수 없습니다. (%c)\n", op);
                return 0;
            }
            return (x / y);
        case '%': return (x % y);
            default:
                fprintf(stderr, "지원되지 않는 연산자입니다. (%c)\n", op);
            return 0;
    }
}

// 최대공약수를 구한다.
int computer_gcd(int a1, int b1) {
    if (a1 < b1) {
        int tmp = a1;
        a1 = b1;
        b1 = tmp;
    }
    while (b1 != 0) {
        int r = a1 % b1;
        a1 = b1;
        b1 = r;
    }
    return a1;
}

// 파이를 구한다
double compute_pi(int loop_count) {
    double divisor = 1.0;
    double divident = 4.0;
    double sum = 0.0;
    for (int i = 0; i < loop_count; i++) {
        sum += divident / divisor;
        divident *= -1.0;
        divisor += 2.0;
    }
    return sum;
}

// 연습문제 7-19
// 파이를 구한다
double compute_pi2(int loop_count) {
    int count = 0;
    for (int i = 0; i < loop_count; i++) {
        double dist = distance(random_real(), random_real());
        if (dist < 1.0)
            count++;
    }
    return count * 4.0 / loop_count;
}

double random_real() {
    return random() / (double)RAND_MAX * 2.0 - 1.0;
}

double distance(double x, double y) {
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}
