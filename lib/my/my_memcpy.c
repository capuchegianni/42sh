/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_memcpy
*/

#include "my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    while (n--)
        *d++ = *s++;
    return (dest);
}
