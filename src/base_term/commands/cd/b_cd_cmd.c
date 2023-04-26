/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** voyage
*/

#include "base_term.h"

void b_cd_home(shell_t *shell)
{
    char *home = my_getenv(shell->env, "HOME");

    shell->env = b_change_oldpwd(shell->env, getcwd(NULL, 0));
    chdir(home);
    shell->env = b_change_pwd(shell->env, getcwd(NULL, 0));
    free(home);
    shell->return_val = 0;
}

void b_cd_back(shell_t *shell)
{
    char *temp = getcwd(NULL, 0);
    char *oldpwd = my_getenv(shell->env, "OLDPWD");

    chdir(oldpwd);
    shell->env = b_change_oldpwd(shell->env, temp);
    shell->env = b_change_pwd(shell->env, getcwd(NULL, 0));
    free(oldpwd);
    shell->return_val = 0;
}

void b_cd_path(shell_t *shell)
{
    char *temp = getcwd(NULL, 0);

    if (chdir(shell->cmd[1]) == -1) {
        dprintf(2, "%s: %s.\n", shell->cmd[1], strerror(errno));
        shell->return_val = 1;
        free(temp);
    } else {
        shell->env = b_change_oldpwd(shell->env, temp);
        shell->env = b_change_pwd(shell->env, getcwd(NULL, 0));
        shell->return_val = 0;
    }
}

int b_check_args_nbr(shell_t *shell)
{
    if (my_tablen(shell->cmd) >= 3) {
        dprintf(2, "cd: Too many arguments.\n");
        shell->return_val = 1;
        return (1);
    }
    return (0);
}

int b_cd_cmd(shell_t *shell)
{
    if (my_cmp(shell->cmd[0], "cd") == 0) {
        if (b_check_args_nbr(shell) == 1)
            return (1);
        if ((shell->cmd[1] == NULL || strcmp(shell->cmd[1],"~") == 0)) {
            b_cd_home(shell);
            return (1);
        }
        if (strcmp(shell->cmd[1], "-") == 0) {
            b_cd_back(shell);
            return (1);
        }
        if (shell->cmd[1] != NULL) {
            b_cd_path(shell);
            return (1);
        }
    }
    return (0);
}
