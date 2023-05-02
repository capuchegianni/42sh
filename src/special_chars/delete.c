/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** delete
*/

#include "project.h"

void update_buffer(shell_t *shell)
{
    int i = shell->cursor_pos;

    for (; shell->buffer[i]; i++)
        shell->buffer[i] = shell->buffer[i + 1];
    shell->buffer[i] = '\0';
}

int my_delete(int c, shell_t *shell)
{
    if ((c == 8 || c == 127)) {
        if (shell->cursor_pos > 0) {
            shell->len--;
            shell->cursor_pos--;
            update_buffer(shell);
            update_prompt_cmd(shell);
        }
        return (1);
    }
    return (0);
}
