/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_getenv
*/

#include "my.h"

char *my_getenv(char **my_env, char *str)
{
    int i = my_searchintab(my_env, str);
    char *temp = NULL;
    int j = 0;

    if (i == -1)
        return (NULL);
    temp = malloc(sizeof(char) * my_strlen(my_env[i]) + 1);
    if (!temp)
        return (NULL);
    for (int k = my_strlen(str) + 1; my_env[i][k]; k++, j++)
        temp[j] = my_env[i][k];
    temp[j] = '\0';
    return (temp);
}
