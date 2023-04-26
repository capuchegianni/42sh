/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** keys
*/

#include "project.h"

int my_left(int c, shell_t *shell, char str[3])
{
    if (str[0] == '[' && str[2] == 'D') {
        if (shell->len > 0) {
            shell->len--;
            printf("\033[D");
            return 1;
        }
    }
    return 0;
}

int my_right(int c, shell_t *shell, char str[3])
{
    if (str[0] == '[' && str[2] == 'C') {
        if (shell->len > 0) {
            shell->len++;
            printf("\033[C");
            return 1;
        }
    }
    return 0;
}
