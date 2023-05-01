/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** unsetenv
*/

#include "project.h"

int my_unsetenv(shell_t *shell)
{
    int i = 0;

    if (my_cmp(shell->cmd[0], "unsetenv") == 0) {
        if (!shell->cmd[1]) {
            dprintf(2, "unsetenv: Too few arguments.\n");
            return shell->return_val = 1;
        }
        i = my_searchintab(shell->env, shell->cmd[1]);
        if (i == -1) {
            shell->return_val = 0;
            return 1;
        }
        shell->env = my_rmlinetab(shell->env, i);
        return 1;
    }
    return 0;
}
