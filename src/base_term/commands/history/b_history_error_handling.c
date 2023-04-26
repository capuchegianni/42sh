/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history_error_handling
*/

#include "base_term.h"

void b_history_error_handling(shell_t *shell)
{
    if (my_tablen(shell->cmd) > 2) {
        dprintf(2, "history: Too many arguments.\n");
        shell->return_val = 1;
        return;
    }
    if (my_tablen(shell->cmd) == 2 && !my_isnum(shell->cmd[1])) {
        dprintf(2, "history: Badly formed number.\n");
        shell->return_val = 1;
        return;
    }
}

void b_hisroty_cmd(shell_t *shell)
{
    b_history_error_handling(shell);
    if (shell->return_val == 1)
        return;
}
