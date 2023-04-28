/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias
*/

#include "project.h"

void free_alias(shell_t *shell)
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

char *get_alias_cmd(shell_t *shell)
{
    char *command = "";

    for (int i = 2; shell->cmd[i]; i++) {
        command = my_strcat(command, shell->cmd[i]);
        if (!command)
            exit(84);
        if (shell->cmd[i + 1])
            command = my_strcat(command, " ");
        if (!command)
            exit(84);
    }
    return (command);
}

int alias_error_handling(shell_t *shell, char *name)
{
    if (strcmp(name, "alias") == 0) {
        dprintf(2, "alias: Too dangerous to alias that.\n");
        shell->return_val = 1;
        return (1);
    }
    return (0);
}

void node_alias(alias_t *current, char *name, char *command)
{
    alias_t *prev_alias = NULL;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            free(current->command);
            current->command = command;
            return;
        }
        prev_alias = current;
        current = current->next;
    }
    current = malloc(sizeof(alias_t));
    current->name = strdup(name);
    current->command = command;
    current->next = NULL;
    prev_alias->next = current;
}

void add_alias(shell_t *shell, char *name)
{
    alias_t *current = shell->alias;
    char *command = get_alias_cmd(shell);

    if (alias_error_handling(shell, name) == 1)
        return;
    if (!shell->alias) {
        init_alias(shell, name, command);
    } else {
        node_alias(current, name, command);
    }
    shell->return_val = 0;
}
