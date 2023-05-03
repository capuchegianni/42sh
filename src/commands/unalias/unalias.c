/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** unalias
*/

#include "project.h"

int remove_alias(shell_t *shell, char *alias)
{
    alias_t *current = shell->alias;
    alias_t *prev = NULL;

    while (current) {
        if (strcmp(current->name, alias) == 0) {
            (!prev) ? (shell->alias = current->next) :
            (prev->next = current->next);
            free(current->name);
            free(current->command);
            free(current);
            return (1);
        }
        prev = current;
        current = current->next;
    }
    shell->return_val = 0;
    return (1);
}

int unalias_cmd(shell_t *shell)
{
    if (my_tablen(shell->cmd) == 1) {
        dprintf(2, "unalias: Too few arguments.\n");
        shell->return_val = 1;
        return (1);
    }
    for (int i = 1; shell->cmd[i]; i++)
        remove_alias(shell, shell->cmd[i]);
    return (1);
}
