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
    if (i == -1)
        return (NULL);
    char *temp = malloc(sizeof(char) * my_strlen(my_env[i]) + 1);
    int j = 0;

    for (int k = my_strlen(str) + 1 ; my_env[i][k] != '\0' ; k++) {
        temp[j] = my_env[i][k];
        j++;
    }
    temp[j] = '\0';
    return (temp);
}
