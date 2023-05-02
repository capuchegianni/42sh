/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exec_alias
*/

#include "project.h"

void change_cmd(shell_t *shell, alias_t *current)
{
    char *command = "";

    if (!shell->first_alias)
        shell->first_alias = my_strdup(shell->cmd[0]);
    command = my_strcat(current->command, " ");
    for (int i = 1; shell->cmd[i]; i++) {
        command = my_strcat(command, shell->cmd[i]);
        command = my_strcat(command, " ");
    }
    shell->cmd = my_wordarray(command, " ");
    if (!shell->cmd)
        exit(84);
    current = shell->alias;
}

int exec_alias(shell_t *shell)
{
    alias_t *current = shell->alias;

    while (current) {
        if (shell->first_alias &&
        strcmp(shell->cmd[0], shell->first_alias) == 0) {
            dprintf(2, "Alias loop.\n");
            shell->return_val = 1;
            return (1);
        }
        if (strcmp(current->name, shell->cmd[0]) == 0) {
            change_cmd(shell, current);
            current = shell->alias;
        } else
            current = current->next;
        shell->return_val = 0;
    }
    return (0);
}
