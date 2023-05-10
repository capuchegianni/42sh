/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** stock_cmds
*/

#include "project.h"

void node_autocpl(auto_complete_t *current, char *name)
{
    auto_complete_t *prev_auto_cpl = NULL;

    while (current) {
        prev_auto_cpl = current;
        current = current->next;
    }
    current = malloc(sizeof(auto_complete_t));
    current->name = strdup(name);
    current->next = NULL;
    prev_auto_cpl->next = current;
}

void add_autocpl(shell_t *shell, char *name)
{
    auto_complete_t *current = shell->auto_cpl;

    if (!shell->auto_cpl) {
        init_autocpl(shell, name);
    } else {
        node_autocpl(current, name);
    }
    shell->return_val = 0;
}

void get_builtins(shell_t *shell)
{
    char *builtins[10] = {"cd", "setenv", "unsetenv", "env", "exit", "echo",
    "alias", "unalias", "history", NULL};

    for (int i = 0; builtins[i]; i++)
        add_autocpl(shell, builtins[i]);
}

void get_all_unix_cmds(shell_t *shell)
{
    DIR *dir;
    struct dirent *entry;

    get_builtins(shell);
    dir = opendir("/usr/bin");
    if (!dir)
        return;
    while ((entry = readdir(dir))) {
        if (entry->d_name[0] != '.')
            add_autocpl(shell, entry->d_name);
    }
}
