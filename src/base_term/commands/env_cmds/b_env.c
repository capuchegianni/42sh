/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env
*/

#include "base_term.h"

void b_print_env(shell_t *shell)
{
    for (int i = 0; shell->env[i]; i++)
        printf("%s\n", shell->env[i]);
}
