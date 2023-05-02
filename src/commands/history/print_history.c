/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** print_history
*/

#include "project.h"

int print_history(shell_t *shell)
{
    history_t *c = shell->history;

    if (!strcmp(shell->cmd[0], "history") || !strcmp(shell->cmd[0], "!")) {
        if (shell->cmd[1] && my_isnum(shell->cmd[1]) == 0) {
            printf("history: Badly formed number.\n");
            return (shell->return_val = 1);
        }
        if (isatty(0) == 0)
            return (1);
        while (c) {
            printf("     %d  %s   %s\n", c->id, c->date, c->command);
            c = c->next;
        }
        return (1);
    }
    return (0);
}
