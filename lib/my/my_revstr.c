/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int total = my_strlen(str);
    char *str2 = malloc(sizeof(char) * total + 1);
    int i = 0;

    if (str2 == NULL)
        return (NULL);
    for (; total > 0 ; total--) {
        str2[i] = str[total - 1];
        i++;
    }
    str2[i] = '\0';
    free(str);
    return str2;
}
