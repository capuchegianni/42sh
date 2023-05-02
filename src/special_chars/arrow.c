/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** arrow
*/

#include "project.h"

void clear_buffer_prompt(shell_t *shell)
{
    for (int i = shell->cursor_pos; i < shell->len; i++)
        printf("\033[C");
    for (int i = shell->len; i > 0; i--)
        printf("\b \b");
}

void updown_arrow_mdvalue(shell_t *shell, history_t *hi)
{
    for (int x = 1; x < shell->arrow_v; x++)
        hi = hi->next;
    clear_buffer_prompt(shell);
    shell->buffer = hi->command;
    shell->len = my_strlen(shell->buffer);
    shell->cursor_pos = shell->len;
    printf("%s", shell->buffer);
}

int print_updown_arrow(shell_t *shell)
{
    int i = 0;
    history_t *hi = shell->history;

    for (history_t *c = shell->history; c; c = c->next)
        i++;
    if (shell->arrow_v < 1)
        shell->arrow_v = 1;
    if (shell->arrow_v >= i + 1) {
        clear_buffer_prompt(shell);
        shell->arrow_v = i + 1;
        shell->buffer = calloc(1, 1);
        shell->len = 0;
        shell->cursor_pos = 0;
        return (0);
    }
    if (!hi)
        return (1);
    updown_arrow_mdvalue(shell, hi);
    return (0);
}

void arrow_handling(shell_t *shell, int c)
{
    if (c == 'D' && shell->cursor_pos > 0) {
        printf("\b");
        shell->cursor_pos--;
    }
    if (c == 'C' && shell->cursor_pos < shell->len) {
        printf("\033[C");
        shell->cursor_pos++;
    }
    if (c == 'A' || c == 'B') {
        if (c == 'A')
            shell->arrow_v--;
        if (c == 'B')
            shell->arrow_v++;
        print_updown_arrow(shell);
    }
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
        arrow_handling(shell, c);
        return (1);
    }
    return (0);
}
