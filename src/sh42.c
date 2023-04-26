/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

int start_window(shell_t *shell)
{
    display_prompt(shell);
    shell->buffer = calloc(1, 1);
    return 0;
}

int open_terminal(shell_t *shell)
{
    int c = 0;

    start_window(shell);
    while ((c = getchar())) {
        if (c == 4)
            break;
        if (shell->return_val == 84)
            return shell->return_val;
        if (scan_input(c, shell) == 1)
            continue;
        shell->buffer = realloc(shell->buffer, shell->len + 2);
        if (shell->buffer == NULL)
            return shell->return_val = 84;
        shell->buffer[shell->len++] = c;
        shell->buffer[shell->len] = '\0';
        printf("%c", c);
    }
    printf("exit\n");
    return shell->return_val;
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
