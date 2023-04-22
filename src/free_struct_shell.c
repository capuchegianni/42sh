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
    my_free_wordarray(shell->env);
    free(shell->buffer);
    free(shell);
}
