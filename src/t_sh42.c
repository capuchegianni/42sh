/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

int start_window(shell_t *shell)
{
    get_all_unix_cmds(shell);
    display_prompt(shell, 0);
    shell->buffer = calloc(1, 1);
    return (0);
}

int open_terminal(shell_t *shell)
{
    start_window(shell);
    for (int c = 0; (c = getchar());) {
        if (c == 4)
            break;
        if (shell->return_val == 84)
            return (shell->return_val);
        if (c != '\t' && c != 8 && c != 127)
            shell->last_id = 0;
        if (scan_input(c, shell))
            continue;
        if (exclude_arrow(shell, c))
            continue;
        shell->buffer = realloc(shell->buffer, shell->len + 2);
        if (shell->buffer == NULL)
            return (shell->return_val = 84);
        add_char(shell, c);
    }
    printf("exit\n\n");
    return (shell->return_val);
}

int my_shell(char **env, shell_t *shell)
{
    int return_val = 0;

    shell->env = init_env(env);
    if (shell->env == NULL)
        return (84);
    fflush(stdout);
    open_terminal(shell);
    return_val = shell->return_val;
    free_struct_shell(shell);
    return (return_val);
}
