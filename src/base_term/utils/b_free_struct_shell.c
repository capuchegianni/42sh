/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free_struct_shell
*/

#include "base_term.h"

void b_free_struct_shell(shell_t *shell)
{
    b_free_history(shell);
    my_free_wordarray(shell->env);
    free(shell->buffer);
    free(shell);
}
