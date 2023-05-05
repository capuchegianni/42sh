/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history_flag
*/

#include "project.h"

void history_c_flag(shell_t *shell)
{
    history_t *c = shell->history;
    int id = 0;

    for (; c->next; c = c->next);
    id = c->id;
    free_history(shell);
    shell->history = malloc(sizeof(history_t));
    shell->history->id = id;
    shell->history->command = my_cleanstr(shell->buffer);
    shell->history->date = get_date();
    shell->history->next = NULL;
    shell->history->prev = NULL;
}

void history_r_flag(shell_t *shell)
{
    history_t *c = shell->history;

    for (; c->next; c = c->next);
    for (; c; c = c->prev) {
        printf("     %d  %s   ", c->id, c->date);
        printf("%s\n", c->command);
    }
}

void history_h_flag(shell_t *shell)
{
    history_t *c = shell->history;

    while (c) {
        printf("%s\n", c->command);
        c = c->next;
    }
}

int detect_flag(shell_t *shell)
{
    if (shell->cmd[1] && shell->cmd[1][0] == '-' &&
    strlen(shell->cmd[1]) == 2) {
        if (shell->cmd[1][1] == 'c') {
            history_c_flag(shell);
            shell->return_val = 0;
            return (1);
        }
        if (shell->cmd[1][1] == 'r') {
            history_r_flag(shell);
            shell->return_val = 0;
            return (1);
        }
        if (shell->cmd[1][1] == 'h') {
            history_h_flag(shell);
            shell->return_val = 0;
            return (1);
        }
    }
    return (0);
}
