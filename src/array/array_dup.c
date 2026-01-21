/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Duplicates an array of any type
*/

#include "my.h"

void *array_dup(void *array)
{
    size_t element_size = sizeof(array[0]);
    size_t length = array_size(array);
    void *new_array = NULL;
    void *src = NULL;
    void *dest = NULL;

    if (array == NULL || element_size == 0 || length == 0)
        return NULL;
    new_array = malloc(element_size * length);
    if (new_array == NULL)
        return NULL;
    for (size_t i = 0; i < length; i++) {
        src = (char *)array + i * element_size;
        dest = (char *)new_array + i * element_size;
        for (size_t j = 0; j < element_size; j++) {
            ((char *)dest)[j] = ((char *)src)[j];
        }
    }
    return new_array;
}
