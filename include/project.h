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

    // Initiation the terminal
    int my_shell(shell_t *shell_struct, char **env);

    // Utils
    void display_prompt(shell_t *my_shell);

    // Special chars handling
    int scan_input(int c, shell_t *my_shell);
    int navigate(shell_t *my_shell);
    int my_newline(int c, shell_t *my_shell);
    int my_delete(int c, shell_t *my_shell);
    int my_left(int c, shell_t *my_shell);
    int my_right(int c, shell_t *my_shell);

#endif /* !PROJECT_H_ */
