/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_auto_cpl
*/

#include "project.h"

void init_auto_cpl(shell_t *shell)
{
    shell->auto_cpl = malloc(sizeof(auto_complete_t));
    if (!shell->auto_cpl)
        return;
    shell->auto_cpl->name = NULL;
    shell->auto_cpl->id = 0;
    shell->auto_cpl->next = NULL;
}
