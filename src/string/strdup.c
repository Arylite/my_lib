/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Capitalizes the first letter of each word in a string
*/

#include <stddef.h>
#include <stdlib.h>

char *strdup(const char *str)
{
    size_t len = 0;
    char *dup = NULL;

    if (str == NULL)
        return NULL;
    while (str[len] != '\0')
        len++;
    dup = (char *) malloc((len + 1) * sizeof(char));
    if (dup == NULL)
        return NULL;
    for (size_t i = 0; i <= len; i++)
        dup[i] = str[i];
    return dup;
}
