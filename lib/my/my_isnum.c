/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-gianni.henriques
** File description:
** my_isnum
*/

#include "my.h"

int my_isnum(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}
