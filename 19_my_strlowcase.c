/*
** EPITECH PROJECT, 2025
** Libmy - my_strlowcase.c
** File description:
** Converts a string to lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    char *orig = str;

    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
        str++;
    }
    return orig;
}
