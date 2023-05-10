/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** stock_cmds
*/

#include "project.h"

void add_cmd(auto_complete_t *current, auto_complete_t *head, char *name)
{
    auto_complete_t *new = malloc(sizeof(auto_complete_t));

    if (!new)
        return;
    if (!head->name) {
        head->name = strdup(name);
        head->id = 0;
        head->next = NULL;
        return;
    }
    new->name = strdup(name);
    new->id = current->id + 1;
    new->next = NULL;
    current->next = new;
}

void get_builtins(auto_complete_t *head)
{
    char *builtins[10] = {"cd", "setenv", "unsetenv", "env", "exit", "echo",
    "alias", "unalias", "history", NULL};
    auto_complete_t *current = head;

    for (int i = 0; builtins[i]; i++) {
        add_cmd(current, head, builtins[i]);
        current = current->next;
    }
}

void get_all_unix_cmds(shell_t *shell)
{
    DIR *dir;
    struct dirent *entry;
    auto_complete_t *head = NULL;
    auto_complete_t *current = NULL;

    init_auto_cpl(shell);
    head = shell->auto_cpl;
    get_builtins(head);
    return;
    current = head;
    for (; current->next; current = current->next);
    dir = opendir("/usr/bin");
    if (!dir)
        return;
    while ((entry = readdir(dir))) {
        if (entry->d_name[0] != '.') {
            add_cmd(current, head, entry->d_name);
            current = current->next;
        }
    }
}
