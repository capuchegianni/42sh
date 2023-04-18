/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct commands_s {
        int i;
        char *last_command;
        char **coms;
    } commands_t;

    typedef struct shell_s {
        char **env;
        char *buffer;
        commands_t *coms;
        int prompt_len;
        int return_val;
    } shell_t;

#endif /* !STRUCT_H_ */
