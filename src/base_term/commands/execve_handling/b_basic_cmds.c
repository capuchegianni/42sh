/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** basic_cmds
*/

#include "base_term.h"

void b_print_exec_errs(shell_t *shell)
{
    if (errno == ENOENT) {
        dprintf(2, "%s: Command not found.\n", shell->cmd[0]);
        return;
    }
    if (errno == ENOTDIR) {
        dprintf(2, "%s: Permission denied.\n", shell->cmd[0]);
        return;
    }
    if (errno == ENOEXEC) {
        dprintf(2, "%s: Exec format error. Wrong Architecture.\n",
        shell->cmd[0]);
        return;
    }
    dprintf(2, "%s: %s.\n", shell->cmd[0], strerror(errno));
}

int b_slash_cmd(shell_t *shell)
{
    if (shell->cmd[0][0] == '.' || shell->cmd[0][0] == '/') {
        if (access(shell->cmd[0], X_OK) == 0)
            return (1);
        b_print_exec_errs(shell);
        return (2);
    }
    return (0);
}

int b_get_valid_path(shell_t *shell, char **tab)
{
    for (int i = 0; tab[i]; i++) {
        strcat(tab[i], "/");
        strcat(tab[i], shell->cmd[0]);
        if (access(tab[i], X_OK) != -1) {
            shell->return_val = execve(tab[i], shell->cmd, shell->env);
            return (shell->return_val);
        }
    }
    return (0);
}

int b_check_all_paths(shell_t *shell)
{
    char *buff = NULL;
    char **tab = NULL;

    if (b_slash_cmd(shell) == 2)
        return (shell->return_val = 1);
    if (b_slash_cmd(shell) == 1) {
        shell->return_val = execve(shell->cmd[0], shell->cmd, shell->env);
        return shell->return_val;
    }
    buff = my_getenv(shell->env, "PATH");
    if (!buff)
        return (shell->return_val = 1);
    tab = my_wordarray(buff, ":=");
    if (!tab)
        return (shell->return_val = 1);
    if (b_get_valid_path(shell, tab) == 0) {
        b_print_exec_errs(shell);
        return (shell->return_val = 1);
    }
    return (shell->return_val = 1);
}

int b_execve_handling(shell_t *shell)
{
    pid_t pid = fork();

    if (pid == -1) {
        dprintf(2, "fork: %s.\n", strerror(errno));
        return (shell->return_val) = 84;
    }
    if (pid == 0) {
        b_check_all_paths(shell);
        if (shell->return_val != 0)
            exit(shell->return_val);
    } else {
        if (wait(&pid) == -1) {
            dprintf(2, "wait: %s.\n", strerror(errno));
            return (shell->return_val = 84);
        }
        shell->return_val = WEXITSTATUS(pid);
    }
    return (shell->return_val);
}
