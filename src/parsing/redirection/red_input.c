/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** red_input
*/

#include "project.h"

int red_input(shell_t *shell, int index)
{
    FILE *fd = fopen(shell->cmd[index], "r");
    char buffer[1000];

    if (fd == NULL)
        return 0;
    while (fgets(buffer, 1000, fd))
        my_printf("%s", buffer);
    shell->red = fd;
    return 1;
}
