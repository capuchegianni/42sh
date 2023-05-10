/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_auto_cpl
*/

#include "project.h"

void init_autocpl(shell_t *shell, char *name)
{
    shell->auto_cpl = malloc(sizeof(auto_complete_t));
    if (!shell->auto_cpl)
        return;
    shell->auto_cpl->name = strdup(name);
    shell->auto_cpl->next = NULL;
    shell->auto_cpl->id = 0;
}
