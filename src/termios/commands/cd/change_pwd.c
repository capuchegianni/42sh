/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** change_pwd
*/

#include "project.h"

int searchintab(char **tab, char *str)
{
    int i = 0;
    for (; tab[i] ; i++) {
        if (my_strncmp(tab[i], str, my_strlen(str)) == 0)
            return (i);
    }
    return (-1);
}

char **change_pwd(char **my_env, char *pwd)
{
    int i = searchintab(my_env, "PWD=");

    free(my_env[i]);
    my_env[i] = malloc(sizeof(char) * (my_strlen(pwd) + 6));
    my_env[i][0] = '\0';
    my_env[i] = strcat(my_env[i], "PWD=");
    my_env[i] = strcat(my_env[i], pwd);
    free(pwd);
    return (my_env);
}

char **change_oldpwd(char **my_env, char *pwd)
{
    int i = searchintab(my_env, "OLDPWD=");

    free(my_env[i]);
    my_env[i] = malloc(sizeof(char) * (my_strlen(pwd) + 9));
    my_env[i][0] = '\0';
    my_env[i] = strcat(my_env[i], "OLDPWD=");
    my_env[i] = strcat(my_env[i], pwd);
    free(pwd);
    return (my_env);
}
