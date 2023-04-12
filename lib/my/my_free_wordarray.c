/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_free
*/

#include "my.h"

void my_free_wordarray(char **array)
{
    int i = 0;

    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}
