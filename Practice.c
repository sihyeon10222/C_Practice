#include <stdio.h>
#include <math.h>

//1
int int_quotient(int first_num_int, int second_num_int);
int int_reminder(int first_num_int, int second_num_int);

//3
int max_num(int x, int y);

//6
int fabs_calc(double num_1, double num_2);

//7
int bit_multipler(int number, int multiplier2);

//10
int first_cordinate_calc(int x_cordinate, int y_cordinate);
int second_cordinate_calc(int x_cordinate, int y_cordinate);
int third_cordinate_calc(int x_cordinate, int y_cordinate);
int fourth_cordinate_calc(int x_cordinate, int y_cordinate);
int no_quadrant(int x_cordinate, int y_cordinate);


int main(void) {

    //CH5 연습문제 1번
    int first_num_int = 10, second_num_int = 3;

    int quotient = int_quotient(first_num_int, second_num_int);
    int reminder = int_reminder(first_num_int, second_num_int);

    printf("%d/%d 몫=%d, 나머지=%d\n", first_num_int, second_num_int, quotient, reminder);


    //CH5 연습문제 3번
    int a = 2, b = 3, c = 4, max;
    int max1 = max_num(a, b);
    int max2 = max_num(max1, c);
    printf("%d\n", max2);


    //CH5 연습문제 6번
    double num1 = 1.0, num2 = 0.9;

    int output = fabs_calc(num1 - num2, 0.1);

    printf("(1.0-0.9)의 결과: %d\n", output);


    //CH5 연습문제 7번
    int number = 10, multiplier2 = 3;

    int bit_output = bit_multipler(number, multiplier2);
    printf("10<<3의 값 : %d\n", bit_output);


    //CH5 연습문제 10번
    int x_cordinate = 10, y_cordinate = 10;

    first_cordinate_calc(x_cordinate, y_cordinate);


    return 0;
}




//1번 정수 몫 구하기
int int_quotient(int first_num_int, int second_num_int) {
    return first_num_int/second_num_int;
}

//1번 정수 나머지 구하기
int int_reminder(int first_num_int, int second_num_int) {
    return first_num_int%second_num_int;
}

//3번 최대값 구하기
int max_num(int x, int y) {
    return ( x > y) ? x : y;
}

//6번 fabs
int fabs_calc(double num_1, double num_2) {
    return fabs (num_1 - num_2) < 0.000001;
}

//7번 비트연산자
int bit_multipler(int number, int multiplier2) {
    return number << multiplier2;
}

//10번 사분면 계산기
int first_cordinate_calc(int x_cordinate, int y_cordinate) {
    return (x_cordinate > 0 && y_cordinate > 0) ? printf("제 1사분면") : second_cordinate_calc(x_cordinate, y_cordinate);
}

int second_cordinate_calc(int x_cordinate, int y_cordinate) {
    return (x_cordinate < 0 && y_cordinate > 0) ? printf("제 2사분면") : third_cordinate_calc(x_cordinate, y_cordinate);
}

int third_cordinate_calc(int x_cordinate, int y_cordinate) {
    return (x_cordinate < 0 && y_cordinate < 0) ? printf("제 3사분면") : fourth_cordinate_calc(x_cordinate, y_cordinate);
}

int fourth_cordinate_calc(int x_cordinate, int y_cordinate) {
    return (x_cordinate > 0 && y_cordinate < 0) ? printf("제 4사분면") : no_quadrant(x_cordinate, y_cordinate);
}

int no_quadrant(int x_cordinate, int y_cordinate) {
    return printf("사분면에 속하지 않습니다.");
}