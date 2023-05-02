/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exit
*/

#include "project.h"

int two_args(shell_t *shell, int i, char *str)
{
    if (i == 2) {
        str = my_strdup(shell->cmd[1]);
        if (my_strisalpha(str) == 1) {
            my_putstr("exit: Expression Syntax.\n");
            return (1);
        }
        if (my_isnum(shell->cmd[1]) == 0) {
            my_putstr("exit: Badly formed number.\n");
            return (1);
        }
        my_putstr("exit\n");
        free_struct_shell(shell);
        exit(my_getnbr(str));
    }
    return 0;
}

int my_exit(shell_t *shell)
{
    int i = my_tablen(shell->cmd);
    char *str = NULL;

    if (my_cmp(shell->cmd[0], "exit") == 0) {
        if (i == 1) {
            my_putstr("exit\n");
            free_struct_shell(shell);
            exit(0);
        }
        if (i > 2) {
            my_putstr("exit: Expression Syntax.\n");
            return (1);
        }
        if (two_args(shell, i, str) == 1)
            return (shell->return_val = 1);
    }
    return (0);
}
