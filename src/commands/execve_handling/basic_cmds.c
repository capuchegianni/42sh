/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** basic_cmds
*/

#include "project.h"

int slash_cmd(shell_t *shell)
{
    if (shell->cmd[0][0] == '.' || shell->cmd[0][0] == '/') {
        if (access(shell->cmd[0], X_OK) == 0)
            return (1);
        print_exec_errs(shell);
        return (2);
    }
    return (0);
}

int get_valid_path(shell_t *shell, char **tab)
{
    char *cmd = strdup(shell->cmd[0]);

    for (int i = 0; tab[i]; i++) {
        strcat(tab[i], "/");
        strcat(tab[i], shell->cmd[0]);
        if (access(tab[i], X_OK) != -1) {
            shell->return_val = execve(tab[i], shell->cmd, shell->env);
            return (shell->return_val);
        }
    }
    shell->cmd[0] = strdup(cmd);
    free(cmd);
    return (0);
}

int check_all_paths(shell_t *shell)
{
    char *buff = NULL;
    char **tab = NULL;

    if (slash_cmd(shell) == 2)
        return (shell->return_val = 1);
    if (slash_cmd(shell) == 1)
        shell->return_val = execve(shell->cmd[0], shell->cmd, shell->env);
    buff = my_getenv(shell->env, "PATH");
    if (!buff)
        return (shell->return_val = 1);
    tab = my_wordarray(buff, ":=");
    if (!tab)
        return (shell->return_val = 1);
    if (get_valid_path(shell, tab) == 0)
        shell->return_val = execve(shell->cmd[0], shell->cmd, shell->env);
    print_exec_errs(shell);
    free(buff);
    my_free_wordarray(tab);
    return (shell->return_val = 1);
}

int execve_handling(shell_t *shell)
{
    pid_t pid = fork();

    if (pid == -1) {
        dprintf(2, "fork: %s.\n", strerror(errno));
        return (shell->return_val) = 84;
    }
    if (pid == 0) {
        check_all_paths(shell);
        if (shell->return_val != 0)
            exit(shell->return_val);
    } else {
        if (wait(&pid) == -1) {
            dprintf(2, "wait: %s.\n", strerror(errno));
            return (shell->return_val = 84);
        }
        shell->return_val = WEXITSTATUS(pid);
        get_exceptions(pid, shell);
    }
    return (shell->return_val);
}
