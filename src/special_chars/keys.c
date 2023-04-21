/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** keys
*/

#include "project.h"

int my_left(int c, shell_t *my_shell)
{
    if (c == KEY_LEFT && my_shell->col >= my_shell->prompt_len) {
        if (my_shell->col == my_shell->prompt_len)
            return 1;
        my_shell->col--;
        move(my_shell->row, my_shell->col);
        return 1;
    }
    return 0;
}

int my_right(int c, shell_t *my_shell)
{
    if (c == KEY_RIGHT) {
        my_shell->col++;
        move(my_shell->row, my_shell->col);
        return 1;
    }
    return 0;
}
