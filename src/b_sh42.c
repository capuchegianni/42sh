/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

void back_sn(char *cmd, shell_t *shell)
{
    char *sp_cmd = NULL;

    for (int i = 0, s = 0; cmd[i]; i++) {
        if (cmd[i + 1] && cmd[i] == '\\' && cmd[i + 1] == 'n') {
            sp_cmd = getcmd(cmd, s, i);
            i += 2;
        }
        if (i == my_strlen(cmd) - 1)
            sp_cmd = getcmd(cmd, s, i + 1);
        if (sp_cmd) {
            shell->buffer = sp_cmd;
            add_command_history(shell);
            separate_all_commands(shell);
            s = i;
        }
        if (sp_cmd)
            sp_cmd = NULL;
    }
}

int b_open_terminal(shell_t *shell)
{
    size_t len;
    char *cmd = NULL;

    while (getline(&cmd, &len, stdin) != -1) {
        if (cmd[0] == '\n' || !cmd[0])
            continue;
        if (cmd[strlen(cmd) - 3] == '\\' && cmd[strlen(cmd) - 2] == 'n')
            cmd[strlen(cmd) - 3] = '\0';
        back_sn(cmd, shell);
    }
    return (shell->return_val);
}

int b_my_shell(char **env, shell_t *shell)
{
    int return_val = 0;

    shell->env = init_env(env);
    if (shell->env == NULL)
        return (84);
    b_open_terminal(shell);
    return_val = shell->return_val;
    free_struct_shell(shell);
    return (return_val);
}
