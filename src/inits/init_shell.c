/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_shell
*/

#include "project.h"

void init_shell_split(shell_t *shell)
{
    shell->env = NULL;
    shell->buffer = NULL;
    shell->len = 0;
    shell->prev_len = 0;
    shell->return_val = 0;
    shell->history = NULL;
    shell->alias = NULL;
    shell->cmd = NULL;
    shell->last_char = 0;
    shell->cursor_pos = 0;
    shell->first_alias = NULL;
    shell->arrow_v = 1;
}

shell_t *init_shell(shell_t *shell, struct termios old_term)
{
    shell = malloc(sizeof(shell_t));
    init_shell_split(shell);
    if (isatty(0)) {
        tcgetattr(0, &old_term);
        shell->term = old_term;
        shell->term.c_lflag &= ~(ICANON | ECHO | ISIG);
        shell->term.c_cc[VMIN] = 1;
        shell->term.c_cc[VTIME] = 0;
        tcsetattr(0, TCSANOW, &shell->term);
    }
    return (shell);
}
