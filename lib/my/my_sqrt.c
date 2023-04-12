/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_computesquareroot
*/

#include "my.h"

double my_sqrt(int nb)
{
    double nbr = 0;
    double temp = 0;

    if (nb < 0)
        return 0;
    nbr = nb / 2;
    while (nbr != temp) {
        temp = nbr;
        nbr = (nb / temp + temp) / 2;
    }
    return nbr;
}
