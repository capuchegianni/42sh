/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** newline
*/

#include "project.h"

void update_arrow_value(shell_t *shell)
{
    history_t *his = shell->history;
    int i = 1;

    for (; his; his = his->next)
        i++;
    shell->arrow_v = i + 1;
}

int my_newline(int c, shell_t *shell)
{
    if (c == '\n') {
        printf("\n");
        if (!shell->buffer[0]) {
            display_prompt(shell, 1);
            return (1);
        }
        update_arrow_value(shell);
        add_command_history(shell);
        separate_all_commands(shell);
        display_prompt(shell, 1);
        shell->buffer = calloc(1, 1);
        shell->len = 0;
        shell->cursor_pos = 0;
        return (1);
    }
    return (0);
}
