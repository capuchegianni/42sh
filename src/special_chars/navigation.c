/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** navigation
*/

#include "project.h"

int navigate(shell_t *my_shell)
{
    MEVENT event;

    if (getmouse(&event) == OK) {
        if (event.bstate & BUTTON4_PRESSED) {
            my_shell->row++;
            move(my_shell->row, my_shell->col);
            wscrl(stdscr, -1);
        }
        if (event.bstate & BUTTON5_PRESSED) {
            my_shell->row--;
            move(my_shell->row, my_shell->col);
            wscrl(stdscr, 1);
        }
    }
    return 0;
}
