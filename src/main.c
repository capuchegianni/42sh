/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** main
*/

#include "project.h"

int main(int ac, char **av, char **env)
{
    int return_val = 0;

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
    return_val = my_shell(env);
    return (return_val);
}
