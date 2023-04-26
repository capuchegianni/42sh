/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** print_history
*/

#include "base_term.h"

void b_print_history(shell_t *shell)
{
    history_t *c = shell->history;

    while (c) {
        printf("     %d  %s   %s\n", c->id, c->date, c->command);
        c = c->next;
    }
}
