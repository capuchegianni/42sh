/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** display_alias
*/

#include "project.h"

void print_alias(shell_t *shell)
{
    alias_t *current = shell->alias;

    while (current) {
        printf("%s  %s\n", current->name, current->command);
        current = current->next;
    }
}

void print_specify_alias(shell_t *shell)
{
    alias_t *current = shell->alias;

    while (current) {
        if (strcmp(current->name, shell->cmd[1]) == 0) {
            printf("%s\n", current->command);
            return;
        }
        current = current->next;
    }
}
