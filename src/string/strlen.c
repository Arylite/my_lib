/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Counts the number of characters in a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    const char *s = str;

    while (*s)
        ++s;
    return s - str;
}
