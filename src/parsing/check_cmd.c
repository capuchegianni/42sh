/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check_cmd
*/

#include "project.h"

int check_alias_cmd(shell_t *shell)
{
    if (strcmp(shell->cmd[0], "alias") == 0 && my_tablen(shell->cmd) > 2) {
        add_alias(shell, shell->cmd[1]);
        return (1);
    }
    if (strcmp(shell->cmd[0], "alias") == 0 && my_tablen(shell->cmd) == 2) {
        print_specify_alias(shell);
        shell->return_val = 0;
        return (1);
    }
    if (strcmp(shell->cmd[0], "alias") == 0 && my_tablen(shell->cmd) == 1) {
        print_alias(shell);
        shell->return_val = 0;
        return (1);
    }
    shell->first_alias = NULL;
    return (0);
}

int check_cmd_split(shell_t *shell)
{
    if (my_unsetenv(shell) == 1)
        return (1);
    if (print_history(shell) == 1)
        return (1);
    if (check_alias_cmd(shell) == 1)
        return (1);
    if (unalias_cmd(shell) == 1)
        return (1);
    return (0);
}

int check_cmd(shell_t *shell)
{
    if (exec_alias(shell) == 1)
        return (1);
    if (cd_cmd(shell) == 1)
        return (1);
    if (my_exit(shell) == 1)
        return (1);
    if (print_env(shell) == 1)
        return (1);
    if (my_setenv(shell) == 1)
        return (1);
    if (echo_cmd(shell) == 1)
        return (1);
    if (check_cmd_split(shell) == 1)
        return (1);
    return (0);
}
