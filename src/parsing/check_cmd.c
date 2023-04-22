/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check_cmd
*/

#include "project.h"

void check_cmd(shell_t *shell)
{
    if (strcmp(shell->cmd[0], "cd") == 0)
        cd_cmd(shell);
    if (strcmp(shell->cmd[0], "exit") == 0)
        exit_cmd(shell);
    if (strcmp(shell->cmd[0], "env") == 0)
        env_cmd(shell);
    if (strcmp(shell->cmd[0], "setenv") == 0)
        setenv_cmd(shell);
    if (strcmp(shell->cmd[0], "unsetenv") == 0)
        unsetenv_cmd(shell);
    if (strcmp(shell->cmd[0], "history") == 0 ||
    strcmp(shell->cmd[0][0], "!") == 0)
        history_cmd(shell);
    if (strcmp(shell->cmd[0], "alias") == 0)
        alias_cmd(shell);
    if (strcmp(shell->cmd[0], "unalias") == 0)
        unalias_cmd(shell);
    if (strcmp(shell->cmd[0], "echo") == 0)
        echo_cmd(shell);
}
