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

    while (c) {
        printf("     %d  %s   %s\n", c->id, c->date, c->command);
        c = c->next;
    }
    shell->return_val = 0;
    return (1);
}
