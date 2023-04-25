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
        printw("\n");
        if (shell->buffer == NULL) {
            display_prompt(shell);
            return 1;
        }
        separate_all_commands(shell);
        add_command_history(shell);
        check_cmd(shell);
        execve_handling(shell);
        display_prompt(shell);
        free(shell->buffer);
        shell->buffer = NULL;
        shell->row++;
        shell->col = shell->p_len;
        return 1;
    }
    return 0;
}
