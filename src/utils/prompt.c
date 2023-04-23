/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** prompt
*/

#include "../include/project.h"

void print_usr(shell_t *shell)
{
    char *usr = my_getenv(shell->env, "USER");

    if (usr == NULL)
        usr = "";
    attron(COLOR_PAIR(4));
    printw("(");
    attron(COLOR_PAIR(3));
    printw("%s", usr);
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    printw(") | ");
    shell->prompt_len += my_strlen(usr) + 5;
    free(usr);
}

void find_val(int val_ret, char *str, shell_t *shell)
{
    shell->prompt_len = my_strlen(str) + 3;
    if (isatty(0) == 1) {
        attron(A_BOLD);
        print_usr(shell);
        printw("%s ", str);
        attroff(COLOR_PAIR(4));
        if (val_ret == 0) {
            attron(COLOR_PAIR(1));
            printw("$ ");
            attroff(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
            printw("$ ");
            attroff(COLOR_PAIR(2));
        }
    }
    attroff(A_BOLD);
}

void display_prompt(shell_t *shell)
{
    char *str = NULL;
    char *pwd = getcwd(NULL, 0);
    int slash = 0;
    int i = 0;

    if (pwd == NULL) {
        dprintf(2, "getcwd: %s.\n", strerror(errno));
        return;
    }
    for (; pwd[i] && slash < 3; i++)
        if (pwd[i] == '/')
            slash++;
    if (slash >= 3) {
        str = my_strcat("~/", pwd + i);
        find_val(shell->return_val, str, shell);
        free(str);
    } else
        find_val(shell->return_val, pwd, shell);
    refresh();
    free(pwd);
}
