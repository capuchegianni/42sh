/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free_linked
*/

#include "project.h"

void free_cpl(auto_complete_t *cpl)
{
    auto_complete_t *tmp = NULL;

    while (cpl) {
        tmp = cpl;
        cpl = cpl->next;
        free(tmp->name);
        free(tmp);
    }
}
