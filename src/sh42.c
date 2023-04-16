/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** sh42
*/

#include "project.h"

int start_window(shell_t *my_shell)
{
    mousemask(ALL_MOUSE_EVENTS, NULL);
    noecho();
    my_shell->win = newwin(1920, 1080, 0, 0);
    keypad(my_shell->win, TRUE);
    scrollok(my_shell->win, TRUE);
    display_prompt(my_shell);
    my_shell->buffer = malloc(sizeof(char) * 2);
    if (my_shell->buffer == NULL)
        return my_shell->return_val = 84;
    my_shell->buffer[0] = '\0';
    return 0;
}

void open_terminal(shell_t *my_shell)
{
    int c;

    if (start_window(my_shell) == 84)
        return;
    while ((c = wgetch(my_shell->win)) != 4) {
        my_shell->buffer = my_realloc(my_shell->buffer, my_shell->col - 72 + 2);
        if (my_shell->buffer == NULL) {
            my_shell->return_val = 84;
            return;
        }
        if (scan_input(c, my_shell) == 1)
            continue;
        waddch(my_shell->win, c);
        my_shell->buffer[my_shell->col - 72] = c;
        my_shell->buffer[my_shell->col - 71] = '\0';
        my_shell->col++;
        wrefresh(my_shell->win);
    }
}

char **init_env(char **env)
{
    char **new_env = malloc(sizeof(char *) * (my_tablen(env) + 1));
    int i = 0;

    if (new_env == NULL)
        return (NULL);
    for (; env[i]; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[i] = NULL;
    return (new_env);
}

void init_colors(void)
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int my_shell(shell_t *my_shell, char **env)
{
    my_shell->env = init_env(env);

    if (my_shell->env == NULL) {
        my_free_wordarray(my_shell->env);
        return (84);
    }
    init_colors();
    open_terminal(my_shell);
    my_free_wordarray(my_shell->env);
    delwin(my_shell->win);
    endwin();
    return (my_shell->return_val);
}
