/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** base_term
*/

#ifndef BASE_TERM_H_
    #define BASE_TERM_H_

    #include "../lib/my/my.h"
    #include <time.h>
    #include <termios.h>
    #include "struct.h"

    // defines
    #define RED "\033[1;31m"
    #define GREEN "\033[1;32m"
    #define YELLOW "\033[1;33m"
    #define BLUE "\033[1;34m"
    #define RESET "\033[0m"

    // Initers
    shell_t *b_init_shell(shell_t *shell, struct termios old_term);
    char **b_init_env(char **env);
    void b_init_history(shell_t *shell);
    void b_init_alias(shell_t *shell, char *name, char *command);

    // Starting the terminal
    int b_my_shell(char **env, shell_t *shell);

    // Utils
    void b_free_struct_shell(shell_t *shell);

    // Parsing
    void b_separate_all_commands(shell_t *shell);
    int b_check_cmd(shell_t *shell);

    // Execve handling
    int b_execve_handling(shell_t *shell);

    // History handling
    void b_add_command_history(shell_t *shell);
    void b_print_history(shell_t *shell);
    void b_free_history(shell_t *shell);
    char *b_get_date(void);

    // Alias
    void b_add_alias(shell_t *shell, char *name, char *command);
    void b_free_alias(shell_t *shell);

    // cd
    int b_cd_cmd(shell_t *shell);
    char **b_change_pwd(char **my_env, char *pwd);
    char **b_change_oldpwd(char **my_env, char *pwd);

    // env cmds
    int b_my_setenv(shell_t *shell);
    int b_my_unsetenv(shell_t *shell);
    void b_print_env(shell_t *shell);

#endif /* !BASE_TERM_H_ */
