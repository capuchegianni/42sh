/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tab
*/

#include "project.h"

void auto_complete(shell_t *shell, DIR *dir)
{
    struct dirent *dp;
    char **tab = my_wordarray(shell->buffer, " ");
    int i = my_tablen(tab);

    if (shell->cursor_pos != shell->len)
        return;
    while ((dp = readdir(dir))) {
        if (my_strncmp(dp->d_name, tab[i - 1], my_strlen(tab[i - 1])) == 0) {
            shell->buffer = my_strcat(shell->buffer,
            dp->d_name + my_strlen(tab[i - 1]));
            printf("%s", dp->d_name + my_strlen(tab[i - 1]));
            shell->len += my_strlen(dp->d_name + my_strlen(tab[i - 1]));
            shell->cursor_pos += my_strlen(dp->d_name + my_strlen(tab[i - 1]));
            break;
        }
    }
    my_free_wordarray(tab);
}

void print_curr_folder(shell_t *shell, DIR *dir)
{
    struct dirent *dp;

    printf("\n");
    while ((dp = readdir(dir))) {
        if (dp->d_type == DT_DIR && dp->d_name[0] != '.') {
            printf("%s%s/%s  ", BLUE, dp->d_name, RESET);
            continue;
        }
        if (dp->d_type == DT_REG) {
            printf("%s%s%s  ", GREEN, dp->d_name, RESET);
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
