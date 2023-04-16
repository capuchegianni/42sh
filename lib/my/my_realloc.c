/*
** EPITECH PROJECT, 2023
** lemin-gianni
** File description:
** my_realloc
*/

#include "my.h"

void *my_realloc(void *pointer, size_t new_size)
{
    void *new_pointer;

    if (pointer == NULL)
        return (malloc(new_size));
    if (new_size == 0) {
        free(pointer);
        return (NULL);
    }
    new_pointer = malloc(new_size);
    if (new_pointer == NULL)
        return (NULL);
    new_pointer = my_memcpy(new_pointer, pointer, new_size - 1);
    free(pointer);
    return (new_pointer);
}
