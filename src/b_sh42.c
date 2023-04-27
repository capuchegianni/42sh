/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

int b_open_terminal(shell_t *shell)
{
    size_t len;

    while (getline(&shell->buffer, &len, stdin) != -1) {
        if (shell->buffer[0] == '\n' || !shell->buffer[0]) {
            continue;
        }
        add_command_history(shell);
        separate_all_commands(shell);
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
