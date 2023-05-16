/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** stock_cmds
*/

#include "project.h"

void node_autocpl(auto_complete_t *current, char *name, int id)
{
    auto_complete_t *prev_auto_cpl = NULL;

    while (current) {
        prev_auto_cpl = current;
        current = current->next;
    }
    current = malloc(sizeof(auto_complete_t));
    current->name = strdup(name);
    current->id = id;
    current->next = NULL;
    prev_auto_cpl->next = current;
}

void add_autocpl(shell_t *shell, char *name, int id)
{
    auto_complete_t *current = shell->cpl;

    if (!shell->cpl) {
        init_autocpl(shell, name);
    } else {
        node_autocpl(current, name, id);
    }
    shell->return_val = 0;
}

void get_builtins(shell_t *shell)
{
    char *builtins[10] = {"cd", "setenv", "unsetenv", "env", "exit", "echo",
    "alias", "unalias", "history", NULL};

    for (int i = 0; builtins[i]; i++)
        add_autocpl(shell, builtins[i], i);
}

void get_all_unix_cmds(shell_t *shell)
{
    DIR *dir;
    struct dirent *entry;
    int id = 9;

    get_builtins(shell);
    dir = opendir("/usr/bin");
    if (!dir)
        return;
    while ((entry = readdir(dir))) {
        if (entry->d_name[0] != '.') {
            add_autocpl(shell, entry->d_name, id);
            id++;
        }
    }
    closedir(dir);
}
