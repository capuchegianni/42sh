/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** scan_input
*/

#include "project.h"

int scan_input(int c, shell_t *shell)
{
    shell->cursor_y = getcury(stdscr);
    shell->cursor_x = getcurx(stdscr);
    if (shell->cursor_y != shell->row)
        shell->row = shell->cursor_y;
    if (my_newline(c, shell) == 1)
        return 1;
    if (my_delete(c, shell) == 1)
        return 1;
    if (my_tab(c, shell) == 1)
        return 1;
    if (c >= 258 && c <= 261) {
        my_left(c, shell);
        my_right(c, shell);
        return 1;
    }
    if (c == 409 || c == 410) {
        navigate(shell);
        return 1;
    }
    return 0;
}
