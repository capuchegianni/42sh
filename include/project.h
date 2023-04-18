/*
** EPITECH PROJECT, 2023
** project
** File description:
** project
*/

#ifndef PROJECT_H_
    #define PROJECT_H_

    #include "../lib/my/my.h"
    #include "struct.h"

    #define RED "\033[1;31m"
    #define GREEN "\033[1;32m"
    #define YELLOW "\033[1;33m"
    #define BLUE "\033[1;34m"
    #define CLOSE "\033[0m"

    int my_shell(shell_t *shell_struct, char **env);
    void display_prompt(shell_t *my_shell);

#endif /* !PROJECT_H_ */
