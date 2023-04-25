/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tab
*/

#include "project.h"

int my_tab(int c, shell_t *shell)
{
    if (c == '\t') {
        addstr("    ");
        shell->buffer = realloc(shell->buffer,
        shell->col - shell->p_len + 5);
        shell->buffer = my_strcat(shell->buffer, "    ");
        shell->col += 4;
        return 1;
    }
    return 0;
}
