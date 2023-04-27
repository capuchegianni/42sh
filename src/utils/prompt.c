/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** prompt
*/

#include "../include/project.h"
#include "base_term.h"

void print_usr(shell_t *shell, int n)
{
    char *usr = my_getenv(shell->env, "USER");

    if (usr == NULL)
        usr = "";
    if (n == 1)
        printf("\n");
    printf("┌──(\033[1;36m%s\033[0m)-\033[1;33m[\033[0m", usr);
    free(usr);
}

void find_val(int val_ret, char *str, shell_t *shell, int n)
{
    if (isatty(0) == 1) {
        print_usr(shell, n);
        printf("%s%s%s%s]%s\n", WHITE, str, RESET, YELLOW, RESET);
        if (val_ret == 0) {
            printf("└─\033[1;32m$ \033[0m");
        } else {
            printf("└─\033[1;31m$ \033[0m");
        }
    }
}

void display_prompt(shell_t *shell, int n)
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
        find_val(shell->return_val, str, shell, n);
        free(str);
    } else
        find_val(shell->return_val, pwd, shell, n);
    free(pwd);
}
