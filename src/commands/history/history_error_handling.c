/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history_error_handling
*/

#include "project.h"

int history_error_handling(shell_t *shell)
{
    if (my_tablen(shell->cmd) > 2) {
        dprintf(2, "history: Too many arguments.\n");
        shell->return_val = 1;
        return (1);
    }
    if (my_tablen(shell->cmd) == 2 && !my_isnum(shell->cmd[1]) &&
    strcmp(shell->cmd[1], "-c") != 0 && strcmp(shell->cmd[1], "-r") != 0 &&
    strcmp(shell->cmd[1], "-h") != 0) {
        dprintf(2, "history: Badly formed number.\n");
        shell->return_val = 1;
        return (1);
    }
    return (0);
}
