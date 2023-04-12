/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_putstr
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
