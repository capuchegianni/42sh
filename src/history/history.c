/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** add_command_history
*/

#include "project.h"

char *get_date(void)
{
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    char *date = malloc(sizeof(char) * 6);

    if (!date)
        return (NULL);
    date = strcat(my_tostr(tm_struct->tm_hour), ":");
    date = strcat(date, my_tostr(tm_struct->tm_min));
    return (date);
}

void print_history(shell_t *shell)
{
    history_t *c = shell->history;

    while (c) {
        printw("     %d  %s   %s\n", c->id, c->date, c->command);
        c = c->next;
    }
}

void free_history(shell_t *shell)
{
    history_t *current = shell->history;
    history_t *next = NULL;

    while (current) {
        next = current->next;
        free(current->command);
        free(current->date);
        free(current);
        current = next;
    }
}

void init_history(shell_t *shell)
{
    shell->history = malloc(sizeof(history_t));
    if (!shell->history)
        return;
    shell->history->id = 1;
    shell->history->command = strdup(shell->buffer);
    shell->history->date = get_date();
    shell->history->next = NULL;
    shell->history->prev = NULL;
}

void add_command_history(shell_t *shell)
{
    history_t *current = shell->history;
    history_t *prev_history = NULL;

    if (!shell->history) {
        init_history(shell);
    } else {
        while (current) {
            prev_history = current;
            current = current->next;
        }
        current = malloc(sizeof(history_t));
        current->id = prev_history->id + 1;
        current->command = strdup(shell->buffer);
        current->date = get_date();
        current->next = NULL;
        current->prev = prev_history;
        prev_history->next = current;
    }
}
