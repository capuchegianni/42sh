/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** newline
*/

#include "project.h"

int my_newline(int c, shell_t *my_shell)
{
    if (c == '\n') {
        printw("\n");
        if (my_shell->buffer == NULL) {
            display_prompt(my_shell);
            return 1;
        }
        printw("%s\n", my_shell->buffer);
        display_prompt(my_shell);
        free(my_shell->buffer);
        my_shell->buffer = NULL;
        my_shell->row++;
        my_shell->col = my_shell->prompt_len;
        return 1;
    }
    return 0;
}
