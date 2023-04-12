/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strlen
*/

#include "my.h"

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i;
}
