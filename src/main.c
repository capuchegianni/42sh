/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** main
*/

#include "project.h"

shell_t *init_shell(shell_t *my_shell)
{
    my_shell = malloc(sizeof(shell_t));
    my_shell->env = NULL;
    my_shell->buffer = NULL;
    my_shell->row = 0;
    my_shell->return_val = 0;
    init_history(my_shell);
    return (my_shell);
}

int main(int ac, char **av, char **env)
{
    shell_t *shell_struct = NULL;
    int return_val = 0;

    shell_struct = init_shell(shell_struct);
    if (!shell_struct)
        return (84);
    if (ac != 1 && !av[1]) {
        my_printerr("Usage: ./42sh");
        return (84);
    }
    if (!env) {
        my_printerr("No environment found.\n");
        return (84);
    }
    if (!initscr())
        return (84);
    return_val = my_shell(shell_struct, env);
    free(shell_struct);
    return (return_val);
}
