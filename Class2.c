#include <stdio.h>
#include <math.h>


double f2c(double fahrenheit); //prototype
void print_digits(int number); //procedure
double get_surface(double radius);
double get_volume(double radius);
double get_pyramid_height(double s_length, double s_height, double p_length);
double get_earth_radius(double angle,double distance);


int main(void) {
    //화씨 온도를 섭씨 온도로 변환한다.
    double fahrenheit = 100.0;
    double celsius = f2c(fahrenheit);
    printf("화씨(%f) = 섭씨 %f\n", fahrenheit, celsius);

    //연습문제 5-5
    int number = 23;
    print_digits(number);

    //연습문제 5-8
    double radius = 10.0;
    double surface = get_surface(radius);
    double volume = get_volume(radius);
    printf("반지름 %.1f 의 표면적: 약 %.1f, 체적: 약 %.1f\n", radius, surface, volume);

    //연습문제 5-9
    double s_length = 100, s_height = 20, p_length = 1000;
    double p_heigh = get_pyramid_height(s_length, s_height, p_length);
    printf("지팡이의 높이: %.1f, 지팡이 그림자의 길이: %.1f, 피라미드까지의 거리: %.1f -> 피라미드 높이: %.2f\n",s_length, s_height, p_length, p_heigh);

    //연습문제 5-11
    double angle = 7.2, distance = 900;
    double get_radius = get_earth_radius(angle,distance);
    printf("거리: %.1f, 각도: %.1f -> 지구 반지름: %.2f\n", angle, distance, get_radius);


    return 0;
}


//화씨 온도를 입력 받아서 섭씨 온도로 변환한다.
double f2c(double fahrenheit) {
    return 5.0/9.0*(fahrenheit - 32.0);
}

//100보다 작은 정수를 입력 받아서 자리수의 숫자를 출력한다.
void print_digits(int number) {
    if (!(0 < number && number < 100)) {
        //(0 >= number || number >= 100)
        printf("처리할 수 없습니다. (%d)\n", number);
        return;
    }
    int tens = number / 10;
    int ones = number % 10;
    fprintf(stderr, "정수 %d -> 십의 자리:%d, 일의자리:%d\n", number, tens, ones);
}

//구의 표면적
double get_surface(double radius) {
    return 4 * M_PI * pow(radius, 2.0);
}

//구의 체적
double get_volume(double radius) {
    return (double) 4 / 3 * M_PI * pow(radius, 3.0);
}

//피라미드 높이
double get_pyramid_height(double s_length, double s_height, double p_length) {
    return (s_length / s_height) * p_length;
}

//지구 반지름
double get_earth_radius(double angle,double distance) {
    return (double) (distance * 360) / (2 * M_PI * angle);
}