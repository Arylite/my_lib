/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Duplicates an array of any type
*/

#include "my.h"
#include <stdint.h>

char **my_array_from_strings(char *strings[])
{
    size_t count = 0;
    char **array = NULL;
    
    while (strings[count] != NULL) {
        count++;
    }
    array = malloc((count + 1) * sizeof(char *));
    if (array == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < count; i++) {
        array[i] = strings[i];
    }
    array[count] = NULL;
    return array;
}