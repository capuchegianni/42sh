/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_shell
*/

#include "project.h"

shell_t *init_shell(shell_t *my_shell)
{
    my_shell = malloc(sizeof(shell_t));
    my_shell->env = NULL;
    my_shell->buffer = NULL;
    my_shell->row = 0;
    my_shell->return_val = 0;
    my_shell->history = NULL;
    return (my_shell);
}
