/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env
*/

#include "project.h"

void print_env(shell_t *shell)
{
    for (int i = 0; shell->env[i]; i++)
        printf("%s\n", shell->env[i]);
}
