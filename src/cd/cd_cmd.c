/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** voyage
*/

#include "project.h"

void cd_home(shell_t *shell)
{
    char *home = getenv("HOME");

    shell->env = change_oldpwd(shell->env, getcwd(NULL, 0));
    chdir(home);
    shell->env = change_pwd(shell->env, getcwd(NULL, 0));
    free(home);
    shell->return_val = 0;
}

void cd_back(shell_t *shell)
{
    char *temp = getcwd(NULL, 0);
    char *oldpwd = getenv("OLDPWD");

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
        dprintf(2, "%s: %s.\n", shell->cmd[1], strerror(errno));
        shell->return_val = 1;
        free(temp);
    } else {
        shell->env = change_oldpwd(shell->env, temp);
        shell->env = change_pwd(shell->env, getcwd(NULL, 0));
        shell->return_val = 0;
    }
}

void cd_cmd(shell_t *shell)
{
    if (my_tablen(shell->cmd) >= 3) {
        dprintf(2, "cd: Too many arguments.\n");
        shell->return_val = 1;
        return;
    }
    if (my_tablen(shell->cmd) < 3 &&
    (shell->cmd[1] == NULL || strcmp(shell->cmd[1],"~") == 0)) {
        cd_home(shell);
        return;
    }
    if (my_tablen(shell->cmd) < 3 && strcmp(shell->cmd[1], "-") == 0) {
        cd_back(shell);
        return;
    }
    if (my_tablen(shell->cmd) < 3 && shell->cmd[1] != NULL) {
        cd_path(shell);
    }
}
