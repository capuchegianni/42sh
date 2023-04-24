/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** voyage
*/

#include "project.h"

void cd_home(shell_t *shell)
{
    char *home = my_getenv(shell->env, "HOME");

    shell->env = change_oldpwd(shell->env, getcwd(NULL, 0));
    chdir(home);
    shell->env = change_pwd(shell->env, getcwd(NULL, 0));
    free(home);
    shell->return_val = 0;
}

void cd_back(shell_t *shell)
{
    char *temp = getcwd(NULL, 0);
    char *oldpwd = my_getenv(shell->env, "OLDPWD");

    chdir(oldpwd);
    shell->env = change_oldpwd(shell->env, temp);
    shell->env = change_pwd(shell->env, getcwd(NULL, 0));
    free(oldpwd);
    shell->return_val = 0;
}

void cd_path(shell_t *shell)
{
    char *temp = getcwd(NULL, 0);

    if (chdir(shell->cmd[1]) == -1) {
        printw("\n");
        dprintf(2, "\r\n%s: %s.\n", shell->cmd[1], strerror(errno));
        shell->return_val = 1;
        free(temp);
    } else {
        shell->env = change_oldpwd(shell->env, temp);
        shell->env = change_pwd(shell->env, getcwd(NULL, 0));
        shell->return_val = 0;
    }
}

int check_args_nbr(shell_t *shell)
{
    if (my_tablen(shell->cmd) >= 3) {
        printw("\n");
        dprintf(2, "\r\ncd: Too many arguments.\n");
        shell->return_val = 1;
        return (1);
    }
    return (0);
}

int cd_cmd(shell_t *shell)
{
    if (my_cmp(shell->cmd[0], "cd") == 0) {
        if (check_args_nbr(shell) == 1)
            return (1);
        if ((shell->cmd[1] == NULL || strcmp(shell->cmd[1],"~") == 0)) {
            cd_home(shell);
            return (1);
        }
        if (strcmp(shell->cmd[1], "-") == 0) {
            cd_back(shell);
            return (1);
        }
        if (shell->cmd[1] != NULL) {
            cd_path(shell);
            return (1);
        }
    }
    return (0);
}
