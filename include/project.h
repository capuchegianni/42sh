/*
** EPITECH PROJECT, 2023
** project
** File description:
** project
*/

#ifndef PROJECT_H_
    #define PROJECT_H_

    #include "../lib/my/my.h"
    #include <termios.h>
    #include <dirent.h>
    #include <time.h>
    #include "struct.h"

    // defines
    #define RED "\033[1;31m"
    #define GREEN "\033[1;32m"
    #define YELLOW "\033[1;33m"
    #define BLUE "\033[1;36m"
    #define WHITE "\033[1;37m"
    #define RESET "\033[0m"

    // Initers
    shell_t *init_shell(shell_t *shell, struct termios old_term);
    char **init_env(char **env);
    void init_history(shell_t *shell);
    void init_alias(shell_t *shell, char *name, char *command);

    // Starting the terminal
    int my_shell(char **env, shell_t *shell);
    int b_my_shell(char **env, shell_t *shell);

    // Utils
    void display_prompt(shell_t *shell, int n);
    void free_struct_shell(shell_t *shell);

    // Parsing
    void separate_all_commands(shell_t *shell);
    int check_cmd(shell_t *shell);

    // Special chars handling
    int scan_input(int c, shell_t *shell);
    int my_newline(int c, shell_t *shell);
    int my_delete(int c, shell_t *shell);
    int my_left(int c, shell_t *shell);
    int my_right(int c, shell_t *shell);
    int my_tab(int c, shell_t *shell);

    // Execve handling
    int execve_handling(shell_t *shell);
    void get_exceptions(int p, shell_t *shell);
    void print_exec_errs(shell_t *shell);

    // History handling
    void add_command_history(shell_t *shell);
    void print_history(shell_t *shell);
    void free_history(shell_t *shell);
    char *get_date(void);

    // Alias
    void add_alias(shell_t *shell, char *name);
    void free_alias(shell_t *shell);
    void print_alias(shell_t *shell);
    void print_specify_alias(shell_t *shell);

    // cd
    int cd_cmd(shell_t *shell);
    char **change_pwd(char **my_env, char *pwd);
    char **change_oldpwd(char **my_env, char *pwd);

    // env cmds
    int my_setenv(shell_t *shell);
    int my_unsetenv(shell_t *shell);
    int print_env(shell_t *shell);

#endif /* !PROJECT_H_ */
