/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** setenv
*/

#include "project.h"

void no_arg(shell_t *shell)
{
    for (int i = 0; shell->env[i]; i++)
        printf("%s\n", shell->env[i]);
}

int is_alphanum(char *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] < 'a' || str[i] > 'z') &&
        (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') &&
        str[i] != '_')
            return 0;
        i++;
    }
    return (1);
}

void path_handling(shell_t *shell)
{
    int i = my_searchintab(shell->env, shell->cmd[1]);
    int j = my_tablen(shell->env);
    char *str = shell->cmd[2];

    if (!str)
        str = "";
    shell->env = realloc(shell->env, 8 * (my_tablen(shell->env) + 2));
    if (i == -1) {
        shell->env[j] = my_strcat(shell->cmd[1], "=");
        shell->env[j] = my_strcat(shell->env[j], str);
        shell->env[j + 1] = NULL;
    } else {
        shell->env[i] = my_strcat(shell->cmd[1], "=");
        shell->env[i] = my_strcat(shell->env[i], str);
    }
}

int my_setenv(shell_t *shell)
{
    if (my_cmp(shell->cmd[0], "setenv") == 0) {
        if (!shell->cmd[1]) {
            no_arg(shell);
            return 1;
        }
        if ((shell->cmd[1][0] < 'A' || shell->cmd[1][0] > 'Z') &&
        (shell->cmd[1][0] < 'a' || shell->cmd[1][0] > 'z') &&
        shell->cmd[1][0] != '_') {
            dprintf(2, "setenv: Variable name must begin with a letter.\n");
            return shell->return_val = 1;
        }
        if (is_alphanum(shell->cmd[1]) == 0) {
            dprintf(2, "setenv: Variable name must contain alphanumeric ");
            dprintf(2, "characters.\n");
            return shell->return_val = 1;
        }
        path_handling(shell);
        return 1;
    }
    return 0;
}
