/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env
*/

#include "project.h"

int print_env(shell_t *shell)
{
    if (my_cmp(shell->cmd[0], "env") == 0) {
        for (int i = 0; shell->env[i]; i++)
            printf("%s\n", shell->env[i]);
        return (1);
    }
    return (0);
}
