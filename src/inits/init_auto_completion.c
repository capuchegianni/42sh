/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_auto_cpl
*/

#include "project.h"

void init_autocpl(shell_t *shell, char *name)
{
    shell->cpl = malloc(sizeof(auto_complete_t));
    if (!shell->cpl)
        return;
    shell->cpl->name = strdup(name);
    shell->cpl->next = NULL;
    shell->cpl->id = 0;
}
