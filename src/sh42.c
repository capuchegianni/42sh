/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

void open_terminal(shell_t *my_shell)
{
    size_t len;

    display_prompt(my_shell);
    while (getline(&my_shell->buffer, &len, stdin) != -1) {
        display_prompt(my_shell);
    }
}

char **init_env(char **env)
{
    char **new_env = malloc(sizeof(char *) * (my_tablen(env) + 1));
    int i = 0;

    if (new_env == NULL)
        return (NULL);
    for (; env[i]; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[i] = NULL;
    return (new_env);
}

int my_shell(shell_t *my_shell, char **env)
{
    my_shell->env = init_env(env);

    if (my_shell->env == NULL) {
        my_free_wordarray(my_shell->env);
        return (84);
    }
    open_terminal(my_shell);
    return (my_shell->return_val);
}
