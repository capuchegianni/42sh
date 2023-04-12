/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-gianni.henriques
** File description:
** my_getnbr
*/

#include "my.h"

int compare_nbr(char const *str)
{
    char *nbr = "2147483647";

    if (my_strlen(str) != my_strlen(nbr))
        return 0;
    for (int i = 0 ; str[i] ; i++) {
        if (str[i] == '-')
            i++;
        if (str[i] > nbr[i])
            return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int j = 1;

    if (str[i] == '-') {
        if (my_strlen(str) > 11)
            return 0;
        j = -1;
        i++;
    }
    if (my_strlen(str) > 10 && str[0] != '-')
            return 0;
    if (compare_nbr(str) == 1)
        return 0;
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10 + (str[i] - '0');
    }
    return nb * j;
}
