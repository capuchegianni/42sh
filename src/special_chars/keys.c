/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** keys
*/

#include "project.h"

int my_left(int c, shell_t *shell)
{
    if (c == KEY_LEFT && shell->col >= shell->p_len) {
        if (shell->col == shell->p_len)
            return 1;
        shell->col--;
        move(shell->row, shell->col);
        return 1;
    }
    return 0;
}

int my_right(int c, shell_t *shell)
{
    if (!shell->buffer)
        return 1;
    if (c == KEY_RIGHT &&
    shell->col < shell->p_len + my_strlen(shell->buffer)) {
        shell->col++;
        move(shell->row, shell->col);
        return 1;
    }
    return 0;
}
