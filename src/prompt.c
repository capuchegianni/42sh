/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** prompt
*/

#include "../include/project.h"

void print_usr(shell_t *my_shell)
{
    char *usr = getenv("USER");

    if (usr == NULL)
        usr = "";
    wattron(my_shell->win, COLOR_PAIR(4));
    wprintw(my_shell->win, "(");
    wattron(my_shell->win, COLOR_PAIR(3));
    wprintw(my_shell->win, "%s", usr);
    wattroff(my_shell->win, COLOR_PAIR(3));
    wattron(my_shell->win, COLOR_PAIR(4));
    wprintw(my_shell->win, ") | ");
    my_shell->prompt_len += my_strlen(usr) + 5;
}

void is_error(int val_ret, char *str, shell_t *my_shell)
{
    my_shell->prompt_len = my_strlen(str) + 3;
    if (isatty(0) == 1) {
        wattron(my_shell->win, A_BOLD);
        print_usr(my_shell);
        wprintw(my_shell->win, "%s ", str);
        wattroff(my_shell->win, COLOR_PAIR(4));
        if (val_ret == 0) {
            wattron(my_shell->win, COLOR_PAIR(1));
            wprintw(my_shell->win, "$ ");
            wattroff(my_shell->win, COLOR_PAIR(1));
        } else {
            wattron(my_shell->win, COLOR_PAIR(2));
            wprintw(my_shell->win, "$ ");
            wattroff(my_shell->win, COLOR_PAIR(2));
        }
    }
    wattroff(my_shell->win, A_BOLD);
}

void display_prompt(shell_t *my_shell)
{
    char *str = NULL;
    char *pwd = getcwd(NULL, 0);
    int slash = 0;
    int i = 0;

    if (pwd == NULL) {
        my_printerr("getcwd: %s.\n", strerror(errno));
        return;
    }
    for (; pwd[i] && slash < 3; i++)
        if (pwd[i] == '/')
            slash++;
    if (slash >= 3) {
        str = my_strcat("~/", pwd + i);
        is_error(my_shell->return_val, str, my_shell);
        free(str);
    } else
        is_error(my_shell->return_val, pwd, my_shell);
    wrefresh(my_shell->win);
    free(pwd);
}
