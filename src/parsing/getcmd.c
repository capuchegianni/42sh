/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** getcmd
*/

#include "project.h"

char *getcmd(char *src, int s, int e)
{
    int n = 0;
    char *cmd = malloc(sizeof(char) * (e - s + 1));

    if (!cmd)
        return (NULL);
    for (; s < e ; s++, n++)
        cmd[n] = src[s];
    cmd[n] = '\0';
    return (cmd);
}
