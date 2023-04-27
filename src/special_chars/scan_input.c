/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** scan_input
*/

#include "project.h"

int scan_input(int c, shell_t *shell)
{
    if (my_newline(c, shell) == 1)
        return (1);
    if (my_delete(c, shell) == 1)
        return (1);
    if (my_tab(c, shell) == 1)
        return (1);
    if (c == 'A' && shell->last_char == '[')
        return (0);
    if (c == 'B' && shell->last_char == '[')
        return (0);
    if (c == 'C' && shell->last_char == '[')
        return (0);
    if (c == 'D' && shell->last_char == '[')
        return (0);
    shell->last_char = c;
    return (0);
}
