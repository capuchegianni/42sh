/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** delete
*/

#include "project.h"

int my_delete(int c, shell_t *shell)
{
    if (c == KEY_BACKSPACE && shell->col >= shell->prompt_len) {
        if (shell->col == shell->prompt_len)
            return 1;
        shell->col--;
        shell->buffer[shell->col - shell->prompt_len] = '\0';
        move(shell->row, shell->col);
        delch();
        return 1;
    }
    return 0;
}
