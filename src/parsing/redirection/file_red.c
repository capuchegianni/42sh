/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** file_red
*/

#include "project.h"

void close_red(shell_t *shell)
{
    if (shell->red != NULL)
        freopen("/dev/tty", "w", stdout);;
    shell->red = NULL;
}

void save_file(shell_t *shell, int index)
{
    FILE *fd = fopen(shell->cmd[index], "r");
    size_t size;
    char *buffer = NULL;

    while (getline(&buffer, &size, fd) != -1)
        my_printf("%s", buffer);
    fclose(fd);
}

int op_file(shell_t *shell, int index)
{
    char var[1];

    if (my_strlen(shell->cmd[index - 1]) == 2)
        var[0] = 'a';
    else
        var[0] = 'w';
    shell->red = freopen(shell->cmd[index], var, stdout);
    if (shell->red == NULL) {
        shell->red = fopen(shell->cmd[index], var);
        if (shell->red == NULL)
            return 0;
    }
    shell->cmd[index - 1] = NULL;
    shell->cmd[index] = NULL;
    return 1;
}

int open_red(shell_t *shell, int index)
{
    if (shell->cmd[index][0] == '>')
        return op_file(shell, index + 1);
    else
        return red_input(shell, index + 1);
}
