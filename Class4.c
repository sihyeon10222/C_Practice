#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

int is_multiple(int n, int m);
double degree_to_radian(double degree);
double sin_degree(double degree);
int sum_dice(int n);
int sum_recursive(int n);
double compute_e_1(int n);
double compute_e_2(int n);
double factorial(int n);

int main() {
    // 연습문제 8-2
    int n = 30, m = 5;
    int flag = is_multiple(n, m);
    if (flag == 1) {
        printf("%d은 %d의 배수입니다.\n", n, m);
    } else {
        printf("%d은 %d의 배수가 아닙니다.\n", n, m);
    }

    // 연습문제 8-9
    for (int degree = 0; degree <= 180; degree += 10) {
        double sin_value = sin_degree((double)degree);
        printf("%f도의 사인값은 %.5f입니다.\n", (double)degree, sin_value);
    }

    // 연습문제 8-11
    srand(time(NULL));
    int person = sum_dice(3);
    int computer = sum_dice(3);
    printf("사용자의 주사위 합: %d\n", person);
    printf("컴퓨터의 주사위 합: %d\n", computer);
    if (person > computer) {
        printf("사용자의 승리입니다.\n");
    } else if (person < computer) {
        printf("컴퓨터의 승리입니다.\n");
    } else {
        printf("비겼습니다.\n");
    }

    //연습문제 9-6
    int sum_limit = 10;
    int sum = sum_recursive(sum_limit);
    printf("1부터 %d까지의 합은 %d입니다.\n", sum_limit, sum);

    //연습문제 8-15 factorial 사용하기
    double e_1 = compute_e_1(n);
    printf("자연대수 e = %f\n", e_1);

    //연습문제 8-15 factorial 사용 안하기
    double e_2 = compute_e_2(n);
    printf("자연대수 e = %f\n", e_2);

    return 0;
}

//어떤 수의 배수인지를 확인한다.
int is_multiple(int n, int m) {
    return (n % m == 0);
}

//각도를 radian으로 변환한다.
double degree_to_radian(double degree) {
    return degree * M_PI / 180.0;
}

//각도에 대한 sin값을 구한다.
double sin_degree(double degree) {
    return sin(degree_to_radian(degree));
}

//주사위를 n번 던져 나온 눈의 합을 구한다.
int sum_dice(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (rand() % 6) + 1;
    }
    return sum;
}

//1에서 n까지 더하는 순환 함수를 작성한다.
int sum_recursive(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum_recursive(n - 1);
    }
}

//8-15 facotial 사용하기
double compute_e_1(int n) {
    if (n == 0) return 1.0;
    return compute_e_1(n - 1) + 1.0 / factorial(n);
}
double factorial(int n) {
    if (n <= 1) return 1.0;
    else return n * factorial(n - 1);
}

//8-15 factorial 사용 안하기
double compute_e_2(int n) {
    double e_2 = 1.0, factorial_2 = 1.0;

    for (int i = 1; i <= n; i++) {
        factorial_2 *= i;
        e_2 += 1.0 / factorial_2;
    }

    return e_2;
}