/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** errors_printing
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

void get_exceptions(int p, shell_t *shell)
{
    char *str = NULL;

    if (WIFSIGNALED(p)) {
        str = strsignal(WTERMSIG(p));
        if (WTERMSIG(p) == 8)
            str = "Floating exception";
        if (WCOREDUMP(p))
            dprintf(2, "%s (core dumped)\n", str);
        else
            dprintf(2, "%s\n", str);
        shell->return_val = p;
        if (shell->return_val == 11)
            shell->return_val = 139;
        if (shell->return_val == 8)
            shell->return_val = 136;
    }
}
