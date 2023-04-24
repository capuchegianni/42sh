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

    // Initers
    shell_t *init_shell(shell_t *shell);
    void init_colors(void);
    char **init_env(char **env);
    void init_history(shell_t *shell);

    // Starting the terminal
    int my_shell(char **env);

    // Utils
    void display_prompt(shell_t *shell);
    void free_struct_shell(shell_t *shell);

    // Parsing
    void separate_all_commands(shell_t *shell);
    int check_cmd(shell_t *shell);

    // Special chars handling
    int scan_input(int c, shell_t *shell);
    int navigate(shell_t *shell);
    int my_newline(int c, shell_t *shell);
    int my_delete(int c, shell_t *shell);
    int my_left(int c, shell_t *shell);
    int my_right(int c, shell_t *shell);
    int my_tab(int c, shell_t *shell);

    // History handling
    void add_command_history(shell_t *shell);
    void print_history(shell_t *shell);
    void free_history(shell_t *shell);
    char *get_date(void);

    // Alias
    void add_alias(shell_t *shell, char *name, char *command);
    void free_alias(shell_t *shell);

    // cd
    int cd_cmd(shell_t *shell);
    char **change_pwd(char **my_env, char *pwd);
    char **change_oldpwd(char **my_env, char *pwd);

    // env cmds
    int my_setenv(shell_t *shell);
    int my_unsetenv(shell_t *shell);
    void print_env(shell_t *shell);

#endif /* !PROJECT_H_ */
