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
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    scrollok(stdscr, TRUE);
    display_prompt(shell);
    shell->buffer = NULL;
    shell->col = shell->p_len;
    return 0;
}

int open_terminal(shell_t *shell)
{
    int c = 0;

    start_window(shell);
    while ((c = getch())) {
        if (c == 4)
            return shell->return_val;
        if (shell->return_val == 84)
            return shell->return_val;
        if (scan_input(c, shell) == 1)
            continue;
        shell->buffer = realloc(shell->buffer, shell->col - shell->p_len + 2);
        if (shell->buffer == NULL)
            return shell->return_val = 84;
        shell->buffer[shell->col - shell->p_len] = c;
        shell->buffer[shell->col - shell->p_len + 1] = '\0';
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
