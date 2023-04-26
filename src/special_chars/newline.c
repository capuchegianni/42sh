/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** newline
*/

#include "project.h"

int my_newline(int c, shell_t *shell)
{
    if (c == '\n') {
        printf("\n");
        if (!shell->buffer[0]) {
            display_prompt(shell);
            return 1;
        }
        separate_all_commands(shell);
        printf("\"%c\"\n", shell->cmd[0][0]);
        add_command_history(shell);
        if (check_cmd(shell) != 1)
            execve_handling(shell);
        free(shell->buffer);
        display_prompt(shell);
        shell->buffer = calloc(1, 1);
        shell->len = 0;
        return 1;
    }
    return 0;
}
