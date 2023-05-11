/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** processes
*/

#include "project.h"

void child_process(shell_t *shell, int in, int fd[2])
{
    close(fd[0]);
    if (in != STDIN_FILENO) {
        dup2(in, STDIN_FILENO);
        close(in);
    }
    if (shell->pipe->last_cmd) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
    }
    check_all_paths(shell);
    if (shell->return_val != 0)
        exit(shell->return_val);
}

int parent_process(shell_t *shell, int in, int fd[2], pid_t pid)
{
    close(fd[1]);
    if (in != STDIN_FILENO)
        close(in);
    in = fd[0];
    if (wait(&pid) == -1) {
        dprintf(2, "wait: %s.\n", strerror(errno));
        return (shell->return_val = 84);
    }
    shell->return_val = WEXITSTATUS(pid);
    get_exceptions(pid, shell);
    return (shell->return_val);
}
