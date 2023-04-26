/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct history_s {
        int id;
        char *command;
        char *date;
        struct history_s *next;
        struct history_s *prev;
    } history_t;

    typedef struct alias_s {
        char *name;
        char *command;
        struct alias_s *next;
    } alias_t;

    typedef struct shell_s {
        struct termios term;
        char **env;
        char *buffer;
        int len;
        int return_val;
        char **cmd;
        char last_char;
        char *a_up ;
        char *a_down;
        char *a_right;
        char *a_left;
        history_t *history;
        alias_t *alias;
    } shell_t;

#endif /* !STRUCT_H_ */
