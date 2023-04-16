/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** delete
*/

#include "project.h"

int my_delete(int c, shell_t *my_shell)
{
    if (c == KEY_BACKSPACE && my_shell->col >= 72) {
        if (my_shell->col == 72)
            return 1;
        my_shell->col--;
        wmove(my_shell->win, my_shell->row, my_shell->col);
        wdelch(my_shell->win);
        return 1;
    }
    return 0;
}
