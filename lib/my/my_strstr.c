/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * my_strlen(to_find) + 1);

    if (!dest)
        return (NULL);
    if (!to_find)
        return (NULL);
    for (; str[i] ; i++) {
        while (to_find[j] == str[i]) {
            dest[j] = to_find[j];
            j++;
            i++;
        }
        if (my_strlen(dest) == my_strlen(to_find))
            return dest;
        j = 0;
    }
    return NULL;
}
