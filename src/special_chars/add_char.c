/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** add_char
*/

#include "project.h"

void update_prompt_add(shell_t *shell)
{
    for (int i = shell->cursor_pos; i < shell->len; i++)
        printf("\033[C");
    for (int i = shell->len; i > 1; i--)
        printf("\b \b");
    printf("%s", shell->buffer);
    for (int i = shell->len; i > shell->cursor_pos; i--)
        printf("\b");
}

void add_char(shell_t *shell, int c)
{
    char *tmp = strdup(shell->buffer);
    int i = 0;

    if (!tmp)
        return;
    for (i = 0; i < shell->len + 1; i++) {
        if (i == shell->cursor_pos) {
            shell->buffer[i] = c;
            continue;
        }
        if (i > shell->cursor_pos)
            shell->buffer[i] = tmp[i - 1];
        else
            shell->buffer[i] = tmp[i];
    }
    shell->buffer[i] = '\0';
    free(tmp);
    shell->len++;
    shell->cursor_pos++;
    update_prompt_add(shell);
}
