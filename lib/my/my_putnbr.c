/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_putnbr
*/

#include "my.h"

void my_putnbr(long long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb / 10) {
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
