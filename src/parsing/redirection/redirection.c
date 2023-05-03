/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check_cmd
*/

#include "project.h"

static int find_spe_char(shell_t *shell, int i)
{
    int red = 0;

    my_printf("la05\n");
    if (my_cmp(shell->cmd[i], ">") == 0)
        red = 1;
    my_printf("la06\n");
    if (my_cmp(shell->cmd[i], ">>") == 0)
        red = 2;
    if (my_cmp(shell->cmd[i], "<") == 0)
        red = 3;
    if (my_cmp(shell->cmd[i], "<<") == 0)
        red = 4;
    return red;
}

void close_red(shell_t *shell, int index)
{

}

int open_red(shell_t *shell)
{

    return 1;
}

static int check_command(shell_t *shell, int index)
{
    if (index == 0)
        return 0;
    if (my_strlen(shell->cmd[index - 1]) == 0 || shell->cmd[index + 1] == NULL)
        return 0;
    if (my_strlen(shell->cmd[index + 1]) == 0)
        return 0;
    return open_red(shell);
}

int redirection(shell_t *shell)
{
    int nb_red = 0;
    int index = 0;

    my_printf("la00\n");
    for (int i = 0; shell->cmd[i] != NULL; i++) {
        if (find_spe_char(shell, i) != 0) {
            my_printf("la04\n");
            index = i;
            nb_red++;
        }
    }
    my_printf("la01\n");
    if (nb_red == 1)
        if (check_command(shell, index))
            return 1;
    my_printf("la02\n");
    return 0;
}
