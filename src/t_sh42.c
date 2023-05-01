/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

int start_window(shell_t *shell)
{
    display_prompt(shell, 0);
    shell->buffer = calloc(1, 1);
    return (0);
}

int exclude_arrow(shell_t *shell, int c)
{
    if (c == 27 && shell->last_char == 27)
        return (1);
    if (c == 1 && shell->last_char == 91)
        return (1);
    if (c == 91 && shell->last_char == 91)
        return (1);
    if ((c == 'A' || c == 'B' || c == 'C' || c == 'D')
    && shell->last_char == '[') {
        if (c == 'D' && shell->cursor_pos > 0) {
            printf("\b");
            shell->cursor_pos--;
        }
        if (c == 'C' && shell->cursor_pos < shell->len) {
            printf("\033[C");
            shell->cursor_pos++;
        }
        return (1);
    }
    return (0);
}

int open_terminal(shell_t *shell)
{
    start_window(shell);
    for (int c = 0; (c = getchar());) {
        if (c == 4)
            break;
        if (shell->return_val == 84 || shell->return_val == 10)
            return (shell->return_val == 10 ? 0 : 84);
        if (scan_input(c, shell))
            continue;
        if (exclude_arrow(shell, c))
            continue;
        shell->buffer = realloc(shell->buffer, shell->len + 2);
        if (shell->buffer == NULL)
            return (shell->return_val = 84);
        shell->buffer[shell->len++] = c;
        shell->buffer[shell->len] = '\0';
        printf("%c", c);
        shell->cursor_pos++;
    }
    printf("exit\n");
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
