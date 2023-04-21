/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include "project.h"

void separate_all_commands(shell_t *shell)
{
    char **all_commands = my_wordarray(shell->buffer, ";&");

    if (!all_commands)
        return;
    for (int i = 0; all_commands[i] != NULL; i++) {
        parse_or(all_commands[i], shell);
    }
    my_free_wordarray(all_commands);
}

void parse_or(char *command, shell_t *shell)
{
    char **commands = my_wordarray(command, "||");

    if (!commands)
        return;
    for (int i = 0; commands[i] != NULL; i++) {
        parse_command(commands[i], shell);
    }
    my_free_wordarray(commands);
}

void parse_pipes(char *command, shell_t *shell)
{
    char **commands = my_wordarray(command, "|");

    if (!commands)
        return;
    for (int i = 0; commands[i] != NULL; i++) {
        parse_command(commands[i], shell);
    }
    my_free_wordarray(commands);
}
