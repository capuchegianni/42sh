/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-gianni.henriques
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
