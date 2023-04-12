/*
** EPITECH PROJECT, 2023
** Lemin-Fork
** File description:
** my_rmtabline
*/

#include "my.h"

char **my_rmlinetab(char **tab, int line)
{
    int i = 0;
    int j = 0;
    char **new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 1));

    for (; tab[i]; i++) {
        if (i != line) {
            new_tab[j] = my_strdup(tab[i]);
            j++;
        }
    }
    new_tab[j] = NULL;
    my_free_wordarray(tab);
    return (new_tab);
}
