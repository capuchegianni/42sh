/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** print_history
*/

#include "project.h"

void range_history(shell_t *shell, int m)
{
    history_t *c = shell->history;
    int l = 0;
    int a = 0;

    for (; c; c = c->next, l++);
    a = l - m;
    c = shell->history;
    for (int i = 0; i < a; i++, c = c->next);
    while (c) {
        printf("     %d  %s   ", c->id, c->date);
        printf("%s\n", c->command);
        c = c->next;
    }
}

void simple_history(shell_t *shell)
{
    history_t *c = shell->history;

    while (c) {
        printf("     %d  %s   ", c->id, c->date);
        printf("%s\n", c->command);
        c = c->next;
    }
}

int print_history(shell_t *shell)
{
    if (strcmp(shell->cmd[0], "history") == 0) {
        if (history_error_handling(shell) == 1)
            return (1);
        if (detect_flag(shell) == 1)
            return (1);
        if (isatty(0) == 0) {
            shell->return_val = 0;
            return (1);
        }
        if (shell->cmd[1])
            range_history(shell, my_getnbr(shell->cmd[1]));
        else
            simple_history(shell);
        shell->return_val = 0;
        return (1);
    }
    return (0);
}
