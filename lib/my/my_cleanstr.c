/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-gianni.henriques
** File description:
** my_cleanstr
*/

#include "my.h"

char *my_cleanstr(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str2 = str;
    char *str3 = NULL;

    for (; str[i] == ' ' || str[i] == '\n' || str[i] == '\t'; i++);
    for (; str[i]; i++, k++)
        str2[k] = str[i];
    str2[k] = '\0';
    str3 = malloc(sizeof(char) * my_strlen(str2) + 1);
    if (str3 == NULL)
        return (NULL);
    j = my_strlen(str2);
    for (; !str[j] || str[j] == ' ' || str[j] == '\t' || str[j] == '\n'; j--);
    for (k = 0; j >= 0; j--, k++)
        str3[k] = str2[j];
    str3[k] = '\0';
    str3 = my_revstr(str3);
    return str3;
}
