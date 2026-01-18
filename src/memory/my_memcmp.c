/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Compares two memory areas
*/

#include "my.h"

int my_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
    const unsigned char *ptr1 = (const unsigned char *)pointer1;
    const unsigned char *ptr2 = (const unsigned char *)pointer2;

    for (size_t i = 0; i < size; i++) {
        if (ptr1[i] != ptr2[i]) {
            return (int)(ptr1[i] - ptr2[i]);
        }
    }
    return 0;
}
