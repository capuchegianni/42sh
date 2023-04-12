/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strisalpha
*/

#include "my.h"

int my_strisalpha(char *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] < 'a' || str[i] > 'z') &&
        (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ') {
            return 0;
        }
        i++;
    }
    return 1;
}
