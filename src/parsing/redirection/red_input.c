/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** red_input
*/

#include "project.h"

int red_input(shell_t *shell, int index)
{
    shell->red = fopen(shell->cmd[index], "r");
    char buffer[1000];

    if (shell->red == NULL)
        return 0;
    while (fgets(buffer, 1000, shell->red))
        my_printf("%s", buffer);
    shell->red = shell->red;
    return 1;
}
