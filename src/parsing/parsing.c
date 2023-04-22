/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include "project.h"

char *getcmd(char *src, int s, int e)
{
    int i = s;
    int n = 0;
    char *cmd = malloc(sizeof(char) * (e - s + 1));

    if (!cmd)
        return (NULL);
    for (; i < e ; i++, n++)
        cmd[n] = src[i];
    cmd[n] = '\0';
    return (cmd);
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
            printw("'%s'\n", p_cmd);
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