/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

int start_window(shell_t *my_shell)
{
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    scrollok(stdscr, TRUE);
    display_prompt(my_shell);
    my_shell->buffer = NULL;
    my_shell->col = my_shell->prompt_len;
    return 0;
}

int open_terminal(shell_t *my_shell)
{
    int c;

    start_window(my_shell);
    while ((c = getch()) != 4) {
        if (scan_input(c, my_shell) == 1)
            continue;
        my_shell->buffer = my_realloc(my_shell->buffer, \
        my_shell->col - my_shell->prompt_len + 2);
        if (my_shell->buffer == NULL)
            return my_shell->return_val = 84;
        my_shell->buffer[my_shell->col - my_shell->prompt_len] = c;
        my_shell->buffer[my_shell->col - my_shell->prompt_len + 1] = '\0';
        my_shell->col++;
        addch(c);
        refresh();
    }
    return my_shell->return_val;
}

int my_shell(char **env)
{
    shell_t *my_shell = NULL;
    int return_val = 0;

    my_shell = init_shell(my_shell);
    if (!my_shell)
        return (84);
    my_shell->env = init_env(env);
    if (my_shell->env == NULL)
        return (84);
    init_colors();
    open_terminal(my_shell);
    return_val = my_shell->return_val;
    free_struct_shell(my_shell);
    endwin();
    return (return_val);
}
