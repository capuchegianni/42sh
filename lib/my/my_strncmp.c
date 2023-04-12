/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1 ; i++);
    return s1[i] - s2[i];
}
