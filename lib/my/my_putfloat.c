/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_putfloat
*/

#include "my.h"

void func4(char str[], long long entier)
{
    if ((int)str[0] == 57) {
        str[0] = '0';
        if (entier > 0)
            entier += 1;
        if (entier < 0)
            entier -= 1;
    } else {
        str[0] += 1;
    }
    str[1] = '0';
}

void func3(char str[], long long entier)
{
    if ((int)str[2] == 57) {
        if ((int)str[1] == 57) {
            func4(str, entier);
        } else {
            str[1] += 1;
        }
        str[2] = '0';
    } else {
        str[2] += 1;
    }
    str[3] = '0';
}

void func2(char str[], long long entier)
{
    if ((int)str[4] == 57) {
        if ((int)str[3] == 57) {
            func3(str, entier);
        } else {
            str[3] += 1;
        }
        str[4] = '0';
    } else {
        str[4] += 1;
    }
    str[5] = '0';
}

void func1(char str[], long long entier)
{
    if ((int)str[6] >= 53) {
        if ((int)str[5] == 57) {
            func2(str, entier);
        } else {
            str[5] += 1;
        }
    }
    str[6] = '\0';
    my_putnbr(entier);
    my_putchar('.');
    my_putstr(str);
}

void my_putfloat(double nb)
{
    char str[7];
    if (nb > 1.79769e+308) {
        my_putstr("inf");
        return;
    }
    if (nb < -1.79769e+308) {
        my_putstr("-inf");
        return;
    }
    long long entier = (long long)nb;
    if (nb < 0){
        nb *= -1;
    }
    for (int i = 0 ; i < 7 ; i++) {
        nb -= (long long)nb;
        nb *= 10;
        str[i] = (long long)nb + '0';
    }
    func1(str, entier);
}
