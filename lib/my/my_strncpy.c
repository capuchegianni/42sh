/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    if (n > my_strlen(src))
        n = my_strlen(src);
    dest = malloc(sizeof(char) * n + 1);
    if (!dest)
        return (NULL);
    for (; i < n ; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
