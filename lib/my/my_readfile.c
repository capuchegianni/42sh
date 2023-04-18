/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-antman-gianni.henriques
** File description:
** open_file
*/

#include "my.h"

char *my_readfile(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    int size;

    struct stat info;
    if ((stat(filepath, &info)) == -1)
        return NULL;
    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * info.st_size + 1);
    if (!buffer)
        return NULL;
    size = read(fd, buffer, info.st_size);
    if (size == -1)
        return NULL;
    if ((S_ISREG(info.st_mode)) == 0)
        return NULL;
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
