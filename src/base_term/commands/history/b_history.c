/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** add_command_history
*/

#include "base_term.h"

char *b_get_date(void)
{
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    char *date = NULL;
    char *hour = malloc(sizeof(char) * 6);
    char *min = malloc(sizeof(char) * 6);

    sprintf(hour, "%d", tm_struct->tm_hour);
    sprintf(min, "%d", tm_struct->tm_min);
    date = strcat(hour, ":");
    date = strcat(date, min);
    return (date);
}

void b_free_history(shell_t *shell)
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

void b_add_command_history(shell_t *shell)
{
    history_t *current = shell->history;
    history_t *prev_history = NULL;

    if (!shell->history) {
        b_init_history(shell);
    } else {
        while (current) {
            prev_history = current;
            current = current->next;
        }
        current = malloc(sizeof(history_t));
        current->id = prev_history->id + 1;
        current->command = my_cleanstr(shell->buffer);
        current->date = b_get_date();
        current->next = NULL;
        current->prev = prev_history;
        prev_history->next = current;
    }
}
