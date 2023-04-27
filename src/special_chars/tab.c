/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tab
*/

#include "project.h"

int my_tab(int c, shell_t *shell)
{
    if (c == 9) {
        if (shell->len == 0) {
            printf("\n");
            system("ls");
            display_prompt(shell);
            return (1);
        }
        shell->buffer = realloc(shell->buffer, shell->len + 5);
        shell->buffer = my_strcat(shell->buffer, "    ");
        shell->len += 4;
        printf("    ");
        return (1);
    }
    return (0);
}
