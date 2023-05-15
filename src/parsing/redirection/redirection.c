/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirection
*/

#include "project.h"

static int find_spe_char(shell_t *shell, int i)
{
    int red = 0;

    if (my_cmp(shell->cmd[i], ">") == 0)
        red = 1;
    if (my_cmp(shell->cmd[i], ">>") == 0)
        red = 2;
    if (my_cmp(shell->cmd[i], "<") == 0)
        red = 3;
    if (my_cmp(shell->cmd[i], "<<") == 0)
        red = 4;
    return red;
}

static int check_command(shell_t *shell, int index)
{
    if (index == 0)
        return 0;
    if (my_strlen(shell->cmd[index - 1]) == 0 || shell->cmd[index + 1] == NULL)
        return 0;
    if (my_strlen(shell->cmd[index + 1]) == 0)
        return 0;
    return open_red(shell, index);
}

int redirection(shell_t *shell)
{
    int nb_red = 0;
    int index = 0;

    if (!shell->cmd)
        return 0;
    for (int i = 0; shell->cmd[i]; i++) {
        if (find_spe_char(shell, i) != 0) {
            index = i;
            nb_red++;
        }
    }
    if (nb_red == 1)
        if (check_command(shell, index))
            return 1;
    return 0;
}
