/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias
*/

#include "base_term.h"

void b_free_alias(shell_t *shell)
{
    alias_t *current = shell->alias;
    alias_t *next = NULL;

    while (current) {
        next = current->next;
        free(current->name);
        free(current->command);
        free(current);
        current = next;
    }
}

void b_add_alias(shell_t *shell, char *name, char *command)
{
    alias_t *current = shell->alias;
    alias_t *prev_alias = NULL;

    if (!shell->alias) {
        b_init_alias(shell, name, command);
    } else {
        while (current) {
            prev_alias = current;
            current = current->next;
        }
        current = malloc(sizeof(alias_t));
        current->name = strdup(name);
        current->command = strdup(command);
        current->next = NULL;
        prev_alias->next = current;
    }
}
