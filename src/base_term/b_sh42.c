/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "base_term.h"

int b_open_terminal(shell_t *shell)
{
    size_t len;

    shell->buffer = calloc(1, 1);
    while (getline(&shell->buffer, &len, stdin) != -1) {
        b_add_command_history(shell);
        b_separate_all_commands(shell);
    }
    return (shell->return_val);
}

int b_my_shell(char **env, shell_t *shell)
{
    int return_val = 0;

    shell->env = b_init_env(env);
    if (shell->env == NULL)
        return (84);
    b_open_terminal(shell);
    return_val = shell->return_val;
    b_free_struct_shell(shell);
    return (return_val);
}
