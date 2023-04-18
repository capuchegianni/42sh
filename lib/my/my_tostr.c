/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-antman-gianni.henriques
** File description:
** my_nbrtostr
*/

#include "my.h"

int find_nbr(int cop, int i)
{
    while (cop > 0) {
        cop /= 10;
        i++;
    }
    return i;
}

char *convert(int x, int cop, int nb)
{
    int i = 0;
    int power = 0;
    char *result = malloc(sizeof(char) * 100);

    if (!result)
        return (NULL);
    if (cop == 0) {
        result[x] = '0';
        result[x + 1] = '\0';
        return result;
    }
    i = find_nbr(cop, i);
    power = i;
    for (; x < i ; x++) {
        result[x] = (nb % my_pow(10, power))
        / my_pow(10, power - 1) + '0';
        power--;
    }
    result[x] = '\0';
    return (result);
}

char *my_tostr(int nb)
{
    int x = 0;
    int cop = nb;
    char *neg = malloc(sizeof(char) * 2);
    char *result = NULL;

    if (!neg)
        return (NULL);
    neg[x] = '\0';
    if (cop < 0) {
        cop *= -1;
        nb *= -1;
        neg[x] = '-';
        neg[x + 1] = '\0';
    }
    result = convert(x, cop, nb);
    result = my_strcat(neg, result);
    if (result == NULL)
        return (NULL);
    free(neg);
    return result;
}
