/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** file_red
*/

#include "project.h"

void close_red(shell_t *shell)
{
    fclose(shell->red);
}

int op_file(shell_t *shell, int index)
{
    FILE *fd = freopen(shell->cmd[index], "w", stdout);

    if (fd == NULL) {
        fd = fopen(shell->cmd[index], "w");
        if (fd == NULL)
            return 0;
        fclose(fd);
    }
    fd = freopen(shell->cmd[index], "w", stdout);
    if (fd == NULL)
        return 0;
    shell->red = fd;
    return 1;
}

int open_red(shell_t *shell, int index)
{
    if (shell->cmd[index][0] == '>')
        return op_file(shell, index + 1);
    else
        return op_file(shell, index - 1);
}
