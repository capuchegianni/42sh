/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check_cmd
*/

#include "project.h"

void close_red(shell_t *shell)
{
    
}

static int find_spe_char(shell_t *shell, int i)
{
    if (my_cmp(shell->cmd[i], "<") == 0 ||
    my_cmp(shell->cmd[i], ">") == 0 ||
    my_cmp(shell->cmd[i], ">>") == 0 ||
    my_cmp(shell->cmd[i], "<<") == 0)
        return 1;
    return 0;
}

static int check_command(shell_t *shell)
{

    return 0;
}

int redirection(shell_t *shell)
{
    int red = 0;

    for (int i = 0; shell->cmd[i] != NULL; i++)
        red += find_spe_char(shell, i);
    if (red == 1)
        if (check_command(shell))
            return 1;
    return 0;
}
