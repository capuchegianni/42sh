/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** delete
*/

#include "project.h"

int my_delete(int c, shell_t *shell)
{
    if ((c == 8 || c == 127)) {
        if (shell->len > 0) {
            printf("\b \b");
            shell->buffer[shell->len] = '\0';
            shell->len--;
            shell->cursor_pos--;
        }
        return (1);
    }
    return (0);
}
