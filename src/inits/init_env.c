/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_env
*/

#include "project.h"

char **init_env(char **env)
{
    char **new_env = malloc(sizeof(char *) * (my_tablen(env) + 1));
    int i = 0;

    if (new_env == NULL)
        return (NULL);
    for (; env[i]; i++)
        new_env[i] = strdup(env[i]);
    new_env[i] = NULL;
    return (new_env);
}
