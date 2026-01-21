/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Duplicates an array of any type
*/

#include "my.h"

size_t array_size(void *array)
{
    size_t element_size = sizeof(array[0]);

    if (array == NULL || element_size == 0)
        return 0;
    return sizeof(array) / element_size;
}
