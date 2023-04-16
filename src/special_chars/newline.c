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
        wprintw(my_shell->win, "\n");
        display_prompt(my_shell);
        free(my_shell->buffer);
        my_shell->buffer = malloc(sizeof(char) * 1);
        my_shell->buffer[0] = '\0';
        my_shell->row++;
        my_shell->col = 72;
        return 1;
    }
    return 0;
}
