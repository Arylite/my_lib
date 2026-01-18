/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Allocates memory for an array and initializes it to zero
*/

#include "my.h"

void *my_calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);

    if (ptr == NULL) {
        return NULL;
    }
    my_memset(ptr, 0, total_size);
    return ptr;
}
