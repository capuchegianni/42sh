/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check_cmd
*/

#include "base_term.h"

int b_check_cmd(shell_t *shell)
{
    if (b_cd_cmd(shell) == 1)
        return (1);
    if (strcmp(shell->cmd[0], "exit") == 0)
        return (1);
    if (strcmp(shell->cmd[0], "env") == 0)
        b_print_env(shell);
    if (strcmp(shell->cmd[0], "setenv") == 0)
        b_my_setenv(shell);
    if (strcmp(shell->cmd[0], "unsetenv") == 0)
        b_my_unsetenv(shell);
    if (strcmp(shell->cmd[0], "history") == 0 ||
    strcmp(shell->cmd[0], "!") == 0)
        b_print_history(shell);
    if (strcmp(shell->cmd[0], "alias") == 0)
        b_add_alias(shell, shell->cmd[1], shell->cmd[2]);
    if (strcmp(shell->cmd[0], "unalias") == 0)
        return (1);
    if (strcmp(shell->cmd[0], "echo") == 0)
        return (1);
    return (0);
}
