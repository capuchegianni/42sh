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
    printf("%s(%s", BLUE, CLOSE);
    printf("%s%s%s", YELLOW, usr, CLOSE);
    my_shell->prompt_len += my_strlen(usr) + 5;
}

void is_error(int val_ret, char *str, shell_t *my_shell)
{
    my_shell->prompt_len = my_strlen(str) + 3;
    if (isatty(0) == 1) {
        print_usr(my_shell);
        printf("%s) | %s%s ", BLUE, str, CLOSE);
        if (val_ret == 0) {
            printf("%s$%s ", GREEN, CLOSE);
        } else {
            printf("%s$%s ", RED, CLOSE);
        }
    }
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
    } else {
        is_error(my_shell->return_val, pwd, my_shell);
    }
    free(pwd);
}
