/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_shell
*/

#include "base_term.h"

shell_t *b_init_shell(shell_t *shell, struct termios old_term)
{
    shell = malloc(sizeof(shell_t));
    shell->env = NULL;
    shell->buffer = NULL;
    shell->len = 0;
    shell->return_val = 0;
    shell->history = NULL;
    shell->alias = NULL;
    shell->cmd = NULL;
    shell->last_char = 0;
    tcgetattr(0, &old_term);
    shell->term = old_term;
    shell->term.c_lflag &= ~(ICANON | ECHO | ISIG);
    shell->term.c_cc[VMIN] = 1;
    shell->term.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &shell->term);
    return (shell);
}
