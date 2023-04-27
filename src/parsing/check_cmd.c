/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check_cmd
*/

#include "project.h"

int check_cmd(shell_t *shell)
{
    if (cd_cmd(shell) == 1)
        return (1);
    if (strcmp(shell->cmd[0], "exit") == 0)
        return (1);
    if (print_env(shell) == 1)
        return (1);
    if (my_setenv(shell) == 1)
        return (1);
    if (my_unsetenv(shell) == 1)
        return (1);
    if (strcmp(shell->cmd[0], "history") == 0 ||
    strcmp(shell->cmd[0], "!") == 0)
        print_history(shell);
    if (strcmp(shell->cmd[0], "alias") == 0)
        add_alias(shell, shell->cmd[1], shell->cmd[2]);
    if (strcmp(shell->cmd[0], "unalias") == 0)
        return (1);
    if (strcmp(shell->cmd[0], "echo") == 0)
        return (1);
    return (0);
}
