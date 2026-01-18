/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Sets a block of memory to a specific value
*/

#include "my.h"

void *my_memset(void *pointer, int value, size_t count)
{
    unsigned char *ptr = (unsigned char *)pointer;

    for (size_t i = 0; i < count; i++) {
        ptr[i] = (unsigned char)value;
    }
    return pointer;
}
