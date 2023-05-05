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
    char *hour = malloc(sizeof(char) * 6);
    char *min = malloc(sizeof(char) * 6);

    if (!date || !hour || !min)
        return (NULL);
    if (tm_struct->tm_hour < 10)
        sprintf(hour, "0%d", tm_struct->tm_hour);
    else
        sprintf(hour, "%d", tm_struct->tm_hour);
    if (tm_struct->tm_min < 10)
        sprintf(min, "0%d", tm_struct->tm_min);
    else
        sprintf(min, "%d", tm_struct->tm_min);
    sprintf(date, "%s:%s", hour, min);
    free(hour);
    free(min);
    return (date);
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
        current->command = my_cleanstr(shell->buffer);
        current->date = get_date();
        current->next = NULL;
        current->prev = prev_history;
        prev_history->next = current;
    }
}
