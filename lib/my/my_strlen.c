/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
