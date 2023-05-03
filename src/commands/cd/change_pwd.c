/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** change_pwd
*/

#include "project.h"

char **change_pwd(char **my_env, char *pwd)
{
    int i = my_searchintab(my_env, "PWD=");

    free(my_env[i]);
    my_env[i] = calloc(my_strlen(pwd) + 9, 1);
    my_env[i] = strcat(my_env[i], "PWD=");
    my_env[i] = strcat(my_env[i], pwd);
    free(pwd);
    return (my_env);
}

char **change_oldpwd(char **my_env, char *pwd)
{
    int i = my_searchintab(my_env, "OLDPWD=");

    if (i == -1) {
        my_env = realloc(my_env, sizeof(char *) * (my_tablen(my_env) + 2));
        my_env[my_tablen(my_env) - 1] = NULL;
        i = my_tablen(my_env) - 2;
    }
    free(my_env[i]);
    my_env[i] = calloc(my_strlen(pwd) + 9, 1);
    my_env[i] = strcat(my_env[i], "OLDPWD=");
    my_env[i] = strcat(my_env[i], pwd);
    free(pwd);
    return (my_env);
}
