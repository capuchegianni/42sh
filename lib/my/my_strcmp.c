/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strcmp
*/

#include "my.h"

int my_cmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] && s2[i] ; i++);
    return s1[i] - s2[i];
}
