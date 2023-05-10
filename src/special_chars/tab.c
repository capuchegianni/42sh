/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tab
*/

#include "project.h"

int replace_str(shell_t *shell, char **tab, int i)
{
    if (my_strncmp(shell->auto_cpl->name, tab[i - 1],
    my_strlen(tab[i - 1])) == 0) {
        shell->buffer = my_strcat(shell->buffer,
        shell->auto_cpl->name + my_strlen(tab[i - 1]));
        printf("%s", shell->auto_cpl->name + my_strlen(tab[i - 1]));
        shell->len += my_strlen(shell->auto_cpl->name + my_strlen(tab[i - 1]));
        shell->cursor_pos += my_strlen(shell->auto_cpl->name +
        my_strlen(tab[i - 1]));
        return (1);
    }
    return (0);
}

void auto_complete(shell_t *shell, DIR *dir)
{
    char **tab = my_wordarray(shell->buffer, " ");
    int i = my_tablen(tab);
    auto_complete_t *first_cmd = shell->auto_cpl;

    if (shell->cursor_pos != shell->len)
        return;
    shell->auto_cpl = shell->auto_cpl->next;
    for (; shell->auto_cpl->next; shell->auto_cpl = shell->auto_cpl->next) {
        if (replace_str(shell, tab, i))
            break;
    }
    shell->auto_cpl->last_cpl = shell->auto_cpl;
    shell->auto_cpl = first_cmd;
    my_free_wordarray(tab);
}

void is_binary(struct dirent *dp, int i)
{
    if (i == my_strlen(dp->d_name))
        printf("%s%s%s  ", YELLOW, dp->d_name, RESET);
    else
        printf("%s%s%s  ", GREEN, dp->d_name, RESET);
}

void print_curr_folder(shell_t *shell, DIR *dir)
{
    struct dirent *dp;
    int i = 0;

    printf("\n");
    while ((dp = readdir(dir))) {
        i = 0;
        for (; dp->d_name[i] && dp->d_name[i] != '.'; i++);
        if (dp->d_type == DT_DIR && dp->d_name[0] != '.') {
            printf("%s%s/%s  ", BLUE, dp->d_name, RESET);
            continue;
        }
        if (dp->d_type == DT_REG) {
            is_binary(dp, i);
            continue;
        }
    }
    display_prompt(shell, 1);
}

int my_tab(int c, shell_t *shell)
{
    DIR *dir;

    dir = opendir(".");
    if (c == 9) {
        if (shell->len == 0) {
            print_curr_folder(shell, dir);
            closedir(dir);
            return (1);
        }
        auto_complete(shell, dir);
        closedir(dir);
        return (1);
    }
    closedir(dir);
    return (0);
}
