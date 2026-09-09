#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_NONSTDC_NO_DEPRECATE
#define PYEONG_RATE 3.3058
#define A 'a'

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


double compute_volume(double length, double width, double height);
float pyeong_to_meter2(int pyeong);
float add_float2(float f1, float f2);
double compute_kenerge(double mass, double speed);
void alarm_fire(void);
char n2c(int n);


int main(void) {

    // 교재 연습문제 4장 4번
    double length = 30.0, width = 30.0, height = 30.0;

    double volume = compute_volume(length, width, height);

    printf("%.0fx%.0fx%.0f = %.0f\n", length, width, height, volume);


    // 교재 연습문제 4장 5번: 평 -> m^2
    int pyeong = 31;

    float meter2 = pyeong_to_meter2(pyeong);

    printf("%d = %f\n", pyeong, meter2);


    // 교재 연습문제 4장 6번: 두 실수를 더한다.
    float f1 = 3.32E-3;
    float f2 = 9.76E-8;

    float f3 = add_float2(f1, f2);

    printf("(%E, %F) = %f\n", f1, f2, f3);


    // 교재 연습문제 4장 7번
    double mass = 100;
    double speed = 200;

    double kenergy = compute_kenerge(mass, speed);

    printf("%f x %f = %f\n", mass, speed, kenergy);


    // 교재 연습문제 4장 9번
    int n = 1;
    char ch = n2c(n);
    printf("%c %c %c\n", n2c(n), n2c(n+1), n2c(n+2));


    // 교재 연습문제 4장 10번
    alarm_fire();

    return 0;
}


// 직육면체의 부피 계산
double compute_volume(double length, double width, double height) {
    return length * width * height;
}


// 평을 m^2으로 변환
float pyeong_to_meter2(int pyeong) {
    return PYEONG_RATE * pyeong;
}


// 두 실수를 더한다.
float add_float2(float f1, float f2) {
    return f1 + f2;
}


// 운동에너지 계산
double compute_kenerge(double mass, double speed) {
    return 0.5 * mass * speed * speed;
}


// 숫자를 문자로 변환
char n2c(int n) {
    return A+n;료
}


// 알람
void alarm_fire(void) {
    printf("화재가 발생하였습니다. %c\n", '\a');
}

//수정 확인22222