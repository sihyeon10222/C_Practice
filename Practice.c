#include <stdio.h>

int price_calc(int get_hour, int get_age);

int main(void) {
    int get_hour = 13;
    int get_age = 1;

    int price = price_calc(get_hour, get_age);
    printf("요금은 %d원 입니다.\n", price);

    return 0;
}

int price_calc(int get_hour, int get_age) {
    if (get_hour <= 17)
        if (get_age >= 3 && get_age <= 12 || get_age >= 65)
            return 25000;
        else
            return 34000;
    else
        return 10000;
}