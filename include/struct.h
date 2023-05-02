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
        int prev_len;
        int return_val;
        char **cmd;
        char last_char;
        int cursor_pos;
        history_t *history;
        alias_t *alias;
        char *first_alias;
        int arrow_v;
    } shell_t;

#endif /* !STRUCT_H_ */
