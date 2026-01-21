/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Duplicates an array of any type
*/

#include "my.h"
#include <stdint.h>

size_t array_cmp(void *array1, void *array2,
    size_t (*comparator)(void *, void *))
{
    size_t length1 = array_size(array1);
    size_t length2 = array_size(array2);
    size_t min_length = MIN(length1, length2);
    void *elem1 = NULL;
    void *elem2 = NULL;
    size_t cmp_result = 0;

    for (size_t i = 0; i < min_length; i++) {
        elem1 = (char *)array1 + i * sizeof(array1[0]);
        elem2 = (char *)array2 + i * sizeof(array2[0]);
        cmp_result = comparator(elem1, elem2);
        if (cmp_result != 0)
            return cmp_result;
    }
    if (length1 != length2)
        return length1 < length2 ? -1 : 1;
    return 0;
}
