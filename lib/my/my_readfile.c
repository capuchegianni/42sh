/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-antman-gianni.henriques
** File description:
** open_file
*/

#include "my.h"

char *my_readfile_stat(char *filepath)
{
    int fd;
    char *buffer;
    int size;

    struct stat info;
    if ((stat(filepath, &info)) == -1)
        return NULL;
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return NULL;
    if ((buffer = malloc(sizeof(char) * info.st_size + 1)) == NULL)
        return NULL;
    if ((size = read(fd, buffer, info.st_size)) == -1)
        return NULL;
    if ((S_ISREG(info.st_mode)) == 0)
        return NULL;
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

char *my_readfile_gl(char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char *buff = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL) {
        return NULL;
    }
    char *result = malloc(sizeof(char) * 10000);
    if (result == NULL)
        return (NULL);
    while ((read = getline(&buff, &len, fp)) != -1)
        result = my_strcat(result, buff);
    fclose(fp);
    return result;
}
