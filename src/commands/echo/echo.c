/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** echo
*/

#include "project.h"

static int my_echo(shell_t *shell, int nbr_arg)
{
    int option = 0;

    for (int i = 1; shell->cmd[i] != NULL; i++) {
        if (i == 1 && my_cmp(shell->cmd[i], "-n") == 0) {
            option = 1;
            continue;
        }
        my_printf("%s", shell->cmd[i]);
    }
    if (option == 0)
        my_printf("\n");
    return 1;
}

int echo_cmd(shell_t *shell)
{
    int nbr_arg = 0;

    for (; shell->cmd[nbr_arg] != NULL; nbr_arg++);
    if (my_cmp(shell->cmd[0], "echo") == 0)
        return my_echo(shell, nbr_arg);
    return 0;
}
