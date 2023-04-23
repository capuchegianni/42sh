/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_shell
*/

#include "project.h"

shell_t *init_shell(shell_t *shell)
{
    shell = malloc(sizeof(shell_t));
    shell->env = NULL;
    shell->buffer = NULL;
    shell->row = 0;
    shell->return_val = 0;
    shell->history = NULL;
    shell->alias = NULL;
    shell->cmd = NULL;
    return (shell);
}
