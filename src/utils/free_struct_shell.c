/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free_struct_shell
*/

#include "project.h"

void free_struct_shell(shell_t *shell)
{
    free_history(shell);
    free_cpl(shell->cpl);
    free_alias(shell);
    my_free_wordarray(shell->env);
    if (shell->cmd)
        my_free_wordarray(shell->cmd);
    free(shell->buffer);
    free(shell);
}
