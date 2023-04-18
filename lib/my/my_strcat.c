/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int k = 0;
    int j = my_strlen(dest) + my_strlen(src);
    char *tmp = malloc(sizeof(char) * (j + 1));

    if (!tmp)
        return (NULL);
    for (; dest[k]; k++)
        tmp[k] = dest[k];
    for (; src[i]; i++)
        tmp[i + k] = src[i];
    tmp[i + k] = '\0';
    dest = my_strdup(tmp);
    free(tmp);
    return dest;
}
