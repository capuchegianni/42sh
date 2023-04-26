/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** main
*/

#include "project.h"
#include "base_term.h"

int main(int ac, char **av, char **env)
{
    shell_t *shell = NULL;
    int return_val = 0;
    struct termios old_term;

    shell = init_shell(shell, old_term);
    if (!shell)
        return (84);
    if (ac != 1 && !av[1]) {
        dprintf(2, "Usage: ./42sh");
        return (84);
    }
    if (!env) {
        dprintf(2, "No environment found.\n");
        return (84);
    }
    if (isatty(0) == 1)
        return_val = my_shell(env, shell);
    else
        b_my_shell(env, shell);
    return (return_val);
}
