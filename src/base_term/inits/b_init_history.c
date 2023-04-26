/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_history
*/

#include "base_term.h"

void b_init_history(shell_t *shell)
{
    shell->history = malloc(sizeof(history_t));
    if (!shell->history)
        return;
    shell->history->id = 1;
    shell->history->command = strdup(shell->buffer);
    shell->history->date = b_get_date();
    shell->history->next = NULL;
    shell->history->prev = NULL;
}
