/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include "base_term.h"

char *b_getcmd(char *src, int s, int e)
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

void b_stock_cmd(char *cmd, shell_t *shell)
{
    if (shell->cmd)
        my_free_wordarray(shell->cmd);
    shell->cmd = my_wordarray(cmd, " \t\n");
    if (b_check_cmd(shell) != 1)
        b_execve_handling(shell);
}

void b_parse_pipes(char *cmd, shell_t *shell)
{
    char *p_cmd = NULL;

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i] == '|') {
            p_cmd = b_getcmd(cmd, s, i);
            i++;
            s = i;
        }
        if (i == my_strlen(cmd) - 1)
            p_cmd = b_getcmd(cmd, s, i + 1);
        if (p_cmd) {
            b_stock_cmd(p_cmd, shell);
            free(p_cmd);
            p_cmd = NULL;
        }
    }
}

void b_parse_or(char *cmd, shell_t *shell)
{
    char *o_cmd = NULL;

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i + 1] && cmd[i] == '|' && cmd[i + 1] == '|') {
            o_cmd = b_getcmd(cmd, s, i);
            i += 2;
            s = i;
        }
        if (i == my_strlen(cmd) - 1)
            o_cmd = b_getcmd(cmd, s, i + 1);
        if (o_cmd) {
            b_parse_pipes(o_cmd, shell);
            free(o_cmd);
            o_cmd = NULL;
        }
    }
}

void b_separate_all_commands(shell_t *shell)
{
    char *s_cmd = NULL;
    char *cmd = strdup(shell->buffer);

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i] == ';')
            s_cmd = b_getcmd(cmd, s, i);
        for (; cmd[i] == ';'; i++);
        if (cmd[i + 1] && cmd[i] == '&' && cmd[i + 1] == '&') {
            s_cmd = b_getcmd(cmd, s, i);
            i += 2;
        }
        if (i == my_strlen(cmd) - 1)
            s_cmd = b_getcmd(cmd, s, i + 1);
        if (s_cmd) {
            b_parse_or(s_cmd, shell);
            free(s_cmd);
            s_cmd = NULL;
            s = i;
        }
    }
}
