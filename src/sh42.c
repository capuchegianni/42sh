/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

int start_window(shell_t *shell)
{
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    scrollok(stdscr, TRUE);
    display_prompt(shell);
    shell->buffer = NULL;
    shell->col = shell->prompt_len;
    return 0;
}

int open_terminal(shell_t *shell)
{
    int c;

    start_window(shell);
    while ((c = getch()) != 4) {
        if (scan_input(c, shell) == 1)
            continue;
        shell->buffer = my_realloc(shell->buffer, \
        shell->col - shell->prompt_len + 2);
        if (shell->buffer == NULL)
            return shell->return_val = 84;
        shell->buffer[shell->col - shell->prompt_len] = c;
        shell->buffer[shell->col - shell->prompt_len + 1] = '\0';
        shell->col++;
        addch(c);
        refresh();
    }
    return shell->return_val;
}

int my_shell(char **env)
{
    shell_t *shell = NULL;
    int return_val = 0;

    shell = init_shell(shell);
    if (!shell)
        return (84);
    shell->env = init_env(env);
    if (shell->env == NULL)
        return (84);
    init_colors();
    open_terminal(shell);
    return_val = shell->return_val;
    free_struct_shell(shell);
    endwin();
    return (return_val);
}
