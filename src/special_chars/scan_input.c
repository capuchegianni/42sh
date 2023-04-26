/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** scan_input
*/

#include "project.h"

int scan_input(int c, shell_t *shell)
{
    char str[3];

    if (my_newline(c, shell) == 1)
        return 1;
    if (my_delete(c, shell) == 1)
        return 1;
    if (my_tab(c, shell) == 1)
        return 1;
    if (c == 27) {
        if (read(0, str, 3) == 3) {
            // my_left(c, shell, str);
            // my_right(c, shell, str);
            return 1;
        }
    }
    return 0;
}
