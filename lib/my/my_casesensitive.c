/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_casesensitive
*/

#include "my.h"

char *upper_c(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
    return (str);
}

char *lower_c(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
    return (str);
}

char *my_casesensitive(char *str, char *my_case)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!str)
        return (NULL);
    if (!str2)
        return (NULL);
    str2 = my_strcpy(str2, str);
    if (my_cmp(my_case, "up") != 0 && my_cmp(my_case, "low") != 0)
        return (str2);
    if (my_cmp(my_case, "up") == 0)
        str2 = upper_c(str2);
    if (my_cmp(my_case, "low") == 0)
        str2 = lower_c(str2);
    return (str2);
}
