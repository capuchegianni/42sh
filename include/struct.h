/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-gianni.henriques
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct shell_s {
        WINDOW *win;
        char **env;
        char *buffer;
        int row;
        int col;
        int cursor_y;
        int cursor_x;
        int prompt_len;
        int return_val;
    } shell_t;

#endif /* !STRUCT_H_ */
