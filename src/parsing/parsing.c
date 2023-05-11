/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include "project.h"

void stock_cmd(char *cmd, shell_t *shell)
{
    if (shell->cmd)
        my_free_wordarray(shell->cmd);
    shell->cmd = my_wordarray(cmd, " \t\n");
    if (shell->cmd) {
        inhibitor(shell);
        if (check_cmd(shell) != 1)
            execve_handling(shell);
    }
}

void parse_pipes(char *cmd, shell_t *shell)
{
    char **p_cmd = my_wordarray(cmd, "|");

    if (!p_cmd)
        return;
    shell->pipe->is_pipe = 0;
    shell->pipe->first_cmd = 0;
    shell->pipe->last_cmd = 0;
    if (my_tablen(p_cmd) == 1)
        stock_cmd(p_cmd[0], shell);
    for (int i = 0; p_cmd[i] && my_tablen(p_cmd) > 1; i++) {
        shell->pipe->is_pipe = 1;
        if (i == 0)
            shell->pipe->first_cmd = 1;
        if (i == my_tablen(p_cmd) - 1)
            shell->pipe->last_cmd = 1;
        stock_cmd(p_cmd[i], shell);
        shell->pipe->first_cmd = 0;
        shell->pipe->last_cmd = 0;
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
        if (o_cmd)
            parse_pipes(o_cmd, shell);
        if (shell->return_val == 0 && o_cmd)
            break;
        if (o_cmd) {
            free(o_cmd);
            o_cmd = NULL;
        }
    }
}

void parse_sp(char *cmd, shell_t *shell)
{
    char *sp_cmd = NULL;

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i + 1] && cmd[i] == '&' && cmd[i + 1] == '&') {
            sp_cmd = getcmd(cmd, s, i);
            i += 2;
        }
        if (i == my_strlen(cmd) - 1)
            sp_cmd = getcmd(cmd, s, i + 1);
        if (sp_cmd) {
            parse_or(sp_cmd, shell);
            s = i;
        }
        if (shell->return_val != 0 && sp_cmd)
            break;
        if (sp_cmd) {
            free(sp_cmd);
            sp_cmd = NULL;
        }
    }
}

void separate_all_commands(shell_t *shell)
{
    char **all_cmd = my_wordarray(shell->buffer, ";");

    if (!all_cmd)
        return;
    for (int x = 0; all_cmd[x]; x++)
        parse_sp(all_cmd[x], shell);
}
