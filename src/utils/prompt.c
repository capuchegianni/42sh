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
    printf("%s(%s%s%s) | %s", BLUE, YELLOW, usr, BLUE, RESET);
    free(usr);
}

void find_val(int val_ret, char *str, shell_t *shell)
{
    if (isatty(0) == 1) {
        print_usr(shell);
        printf("%s%s%s ", BLUE, str, RESET);
        if (val_ret == 0) {
            printf("%s$ %s", GREEN, RESET);
        } else {
            printf("%s$ %s", RED, RESET);
        }
    }
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
    free(pwd);
}
