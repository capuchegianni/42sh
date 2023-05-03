/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** escape_char
*/

#include "project.h"

void detect_backslash(shell_t *shell, int i, int j)
{
    int k = j;

    if (!shell->cmd[i][j + 1])
        return;
    if (shell->cmd[i][j] == '\\') {
        if (shell->cmd[i][j + 1] == 'n')
            shell->cmd[i][j] = '\n';
        if (shell->cmd[i][j + 1] == 't')
            shell->cmd[i][j] = '\t';
        if (shell->cmd[i][j + 1] == 'b')
            shell->cmd[i][j] = '\b';
        if (shell->cmd[i][j + 1] == 'r')
            shell->cmd[i][j] = '\r';
        for (; shell->cmd[i][k + 2]; k++)
            shell->cmd[i][k + 1] = shell->cmd[i][k + 2];
        shell->cmd[i][k + 1] = '\0';
    }
}

void inhibitor(shell_t *shell)
{
    int i = 0;

    for (; shell->cmd[i]; i++)
        for (int j = 0; shell->cmd[i][j + 1]; j++)
            detect_backslash(shell, i, j);
}
