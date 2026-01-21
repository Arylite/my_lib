/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Duplicates an array of any type
*/

#include "my.h"

static void swap_elements(void *a, void *b, size_t elem_size)
{
    char temp[elem_size];

    my_memcpy(temp, a, elem_size);
    my_memcpy(a, b, elem_size);
    my_memcpy(b, temp, elem_size);
}

static bool bubble_pass(void *array, size_t length, size_t elem_size,
    size_t (*comparator)(void *, void *))
{
    bool swapped = false;
    void *elem1 = NULL;
    void *elem2 = NULL;

    for (size_t i = 0; i < length - 1; i++) {
        elem1 = (char *)array + i * elem_size;
        elem2 = (char *)array + (i + 1) * elem_size;
        if (comparator(elem1, elem2) > 0) {
            swap_elements(elem1, elem2, elem_size);
            swapped = true;
        }
    }
    return swapped;
}

size_t array_sort(void *array, size_t (*comparator)(void *, void *))
{
    size_t length = array_size(array);
    size_t elem_size = sizeof(((char *)array)[0]);

    if (length < 2)
        return length;
    while (bubble_pass(array, length, elem_size, comparator));
    return length;
}
