/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** scan_input
*/

#include "project.h"

int scan_input(int c, shell_t *my_shell)
{
    my_shell->cursor_y = getcury(stdscr);
    my_shell->cursor_x = getcurx(stdscr);
    if (my_shell->cursor_y != my_shell->row)
        my_shell->row = my_shell->cursor_y;
    if (my_newline(c, my_shell) == 1)
        return 1;
    if (my_delete(c, my_shell) == 1)
        return 1;
    if (my_left(c, my_shell) == 1)
        return 1;
    if (my_right(c, my_shell) == 1)
        return 1;
    return 0;
}
