/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_alias
*/

#include "project.h"

void init_alias(shell_t *shell, char *name, char *command)
{
    shell->alias = malloc(sizeof(alias_t));
    if (!shell->alias)
        return;
    shell->alias->name = strdup(name);
    shell->alias->command = strdup(command);
    shell->alias->next = NULL;
    shell->first_alias = NULL;
}
