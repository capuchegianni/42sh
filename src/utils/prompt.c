/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** prompt
*/

#include "project.h"

void print_usr(shell_t *shell, int n)
{
    char *usr = my_getenv(shell->env, "USER");

    if (usr == NULL)
        usr = "";
    if (n == 1)
        printf("\n");
    printf("┌──(%s%s%s)-%s[%s", BLUE, usr, RESET, YELLOW, RESET);
    free(usr);
}

void find_val(int val_ret, char *str, shell_t *shell, int n)
{
    if (isatty(0) == 1) {
        print_usr(shell, n);
        printf("%s%s%s%s]%s\n", WHITE, str, RESET, YELLOW, RESET);
        if (val_ret == 0) {
            printf("└─%s$ %s", GREEN, RESET);
        } else {
            printf("└─%s$ %s", RED, RESET);
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
