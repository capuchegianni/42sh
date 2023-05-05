/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free_history
*/

#include "project.h"

void free_history(shell_t *shell)
{
    history_t *c = shell->history;
    history_t *tmp = NULL;

    while (c) {
        tmp = c;
        c = c->next;
        free(tmp->command);
        free(tmp->date);
        free(tmp);
    }
}
