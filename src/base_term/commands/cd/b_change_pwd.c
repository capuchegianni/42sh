/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** change_pwd
*/

#include "base_term.h"

char **b_change_pwd(char **my_env, char *pwd)
{
    int i = my_searchintab(my_env, "PWD=");

    free(my_env[i]);
    my_env[i] = calloc(my_strlen(pwd) + 9, 1);
    my_env[i] = strcat(my_env[i], "PWD=");
    my_env[i] = strcat(my_env[i], pwd);
    free(pwd);
    return (my_env);
}

char **b_change_oldpwd(char **my_env, char *pwd)
{
    int i = my_searchintab(my_env, "OLDPWD=");

    free(my_env[i]);
    my_env[i] = calloc(my_strlen(pwd) + 9, 1);
    my_env[i] = strcat(my_env[i], "OLDPWD=");
    my_env[i] = strcat(my_env[i], pwd);
    free(pwd);
    return (my_env);
}
