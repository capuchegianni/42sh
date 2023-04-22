/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include "project.h"

char *getcmd(char *src, int s, int e)
{
    int n = 0;
    char *cmd = malloc(sizeof(char) * (e - s + 1));

    if (!cmd)
        return (NULL);
    for (; s < e ; s++, n++)
        cmd[n] = src[s];
    cmd[n] = '\0';
    return (cmd);
}

void stock_cmd(char *cmd, shell_t *shell)
{
    if (shell->cmd)
        my_free_wordarray(shell->cmd);
    shell->cmd = my_wordarray(cmd, " \t\n");
    for (int i = 0; shell->cmd[i]; i++)
        printw("%s ", shell->cmd[i]);
    printw("\n");
}

void parse_pipes(char *cmd, shell_t *shell)
{
    char *p_cmd = NULL;

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i] == '|') {
            p_cmd = getcmd(cmd, s, i);
            i++;
            s = i;
        }
        if (i == my_strlen(cmd) - 1)
            p_cmd = getcmd(cmd, s, i + 1);
        if (p_cmd) {
            stock_cmd(p_cmd, shell);
            free(p_cmd);
            p_cmd = NULL;
        }
    }
}

void parse_or(char *cmd, shell_t *shell)
{
    char *o_cmd = NULL;

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i + 1] && cmd[i] == '|' && cmd[i + 1] == '|') {
            o_cmd = getcmd(cmd, s, i);
            i += 2;
            s = i;
        }
        if (i == my_strlen(cmd) - 1)
            o_cmd = getcmd(cmd, s, i + 1);
        if (o_cmd) {
            parse_pipes(o_cmd, shell);
            free(o_cmd);
            o_cmd = NULL;
        }
    }
}

void separate_all_commands(shell_t *shell)
{
    char *s_cmd = NULL;
    char *cmd = strdup(shell->buffer);

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i] == ';')
            s_cmd = getcmd(cmd, s, i);
        for (; cmd[i] == ';'; i++);
        if (cmd[i + 1] && cmd[i] == '&' && cmd[i + 1] == '&') {
            s_cmd = getcmd(cmd, s, i);
            i += 2;
        }
        if (i == my_strlen(cmd) - 1)
            s_cmd = getcmd(cmd, s, i + 1);
        if (s_cmd) {
            parse_or(s_cmd, shell);
            free(s_cmd);
            s_cmd = NULL;
            s = i;
        }
    }
}
