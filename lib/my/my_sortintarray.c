/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_sortinarray
*/

#include "my.h"

void my_swapint(int *a, int *b)
{
    int rev;
    rev = *a;
    *a = *b;
    *b = rev;
}

void swap_nbrs(int *nbr1, int *nbr2)
{
    if (*nbr1 > *nbr2)
        my_swapint(nbr1, nbr2);
}

void my_sortintarray(int *tab, int size)
{
    for (int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size - 1 - i ; j++) {
            swap_nbrs(&tab[j], &tab[j + 1]);
        }
    }
}
