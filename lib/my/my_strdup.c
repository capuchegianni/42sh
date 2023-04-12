/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *my_dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (my_dest == NULL)
        return NULL;
    for (; src[i]; i++)
        my_dest[i] = src[i];
    my_dest[i] = '\0';
    return my_dest;
}
