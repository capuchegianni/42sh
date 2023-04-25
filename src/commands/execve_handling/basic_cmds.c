/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** basic_cmds
*/

#include "project.h"

void print_exec_errs(shell_t *shell)
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

int slash_cmd(shell_t *shell)
{
    if (shell->cmd[0][0] == '.' || shell->cmd[0][0] == '/') {
        if (access(shell->cmd[0], X_OK) == 0)
            return 1;
        print_exec_errs(shell);
        return 2;
    }
    return 0;
}

int check_all_paths(shell_t *shell)
{
    char *buff = NULL;
    char **tab = NULL;

    if (slash_cmd(shell) == 2)
        return shell->return_val = 1;
    if (slash_cmd(shell) == 1) {
        shell->return_val = execve(shell->cmd[0], shell->cmd, shell->env);
        return shell->return_val;
    }
    buff = my_getenv(shell->env, "PATH");
    if (!buff)
        return shell->return_val = 1;
    tab = my_wordarray(buff, ":=");
    if (!tab)
        return shell->return_val = 1;
    for (int i = 1; tab[i]; i++) {
        strcat(tab[i], "/");
        strcat(tab[i], shell->cmd[0]);
        printw("%s\n", tab[i]);
        if (access(tab[i], X_OK) != -1) {
            printw("\n\r");
            shell->return_val = execve(tab[i], shell->cmd, shell->env);
            return 1;
        }
    }
    return 0;
}

int execve_handling(shell_t *shell)
{
    pid_t pid = fork();

    if (pid == -1) {
        printw("\n");
        dprintf(2, "\r\nfork: %s.\n", strerror(errno));
        return shell->return_val = 84;
    }
    if (pid == 0) {
        check_all_paths(shell);
    } else {
        if (wait(&pid) == -1) {
            printw("\n");
            dprintf(2, "\r\nwait: %s.\n", strerror(errno));
            return shell->return_val = 84;
        }
        shell->return_val = WEXITSTATUS(pid);
    }
    return shell->return_val;
}
