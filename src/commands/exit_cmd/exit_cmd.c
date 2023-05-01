/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit command
*/

#include "project.h"

int exit_cmd(shell_t **ad_shell)
{
    shell_t *shell = *ad_shell;
    if (my_cmp(shell->cmd[0], "exit") == 0) {
        shell->return_val = 10;
        *ad_shell = shell;
        return 1;
    }
    return 0;
}
