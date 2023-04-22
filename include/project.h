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
    #include <time.h>

    // Initiation the terminal
    int my_shell(shell_t *shell_struct, char **env);

    // Utils
    void display_prompt(shell_t *my_shell);
    void free_struct_shell(shell_t *shell);

    // Special chars handling
    int scan_input(int c, shell_t *my_shell);
    int navigate(int c, shell_t *my_shell);
    int my_newline(int c, shell_t *my_shell);
    int my_delete(int c, shell_t *my_shell);
    int my_left(int c, shell_t *my_shell);
    int my_right(int c, shell_t *my_shell);

    // History handling
    void add_command_history(shell_t *shell);
    void print_history(shell_t *shell);
    void free_history(shell_t *shell);

    // Parsing
    void separate_all_commands(shell_t *shell);

#endif /* !PROJECT_H_ */
