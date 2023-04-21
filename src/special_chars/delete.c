/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** delete
*/

#include "project.h"

int my_delete(int c, shell_t *my_shell)
{
    if (c == KEY_BACKSPACE && my_shell->col >= my_shell->prompt_len) {
        if (my_shell->col == my_shell->prompt_len)
            return 1;
        my_shell->col--;
        move(my_shell->row, my_shell->col);
        delch();
        return 1;
    }
    return 0;
}
