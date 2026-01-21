/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Compares two strings, return the difference
*/

#include "my.h"

int my_strcmp_insensitive(const char *s1, const char *s2)
{
    char c1 = 0;
    char c2 = 0;

    while (*s1 && *s2) {
        c1 = (*s1 >= 'A' && *s1 <= 'Z') ? *s1 + 32 : *s1;
        c2 = (*s2 >= 'A' && *s2 <= 'Z') ? *s2 + 32 : *s2;
        if (c1 != c2)
            return (unsigned char)c1 - (unsigned char)c2;
        s1++;
        s2++;
    }
    return (unsigned char)c1 - (unsigned char)c2;
}
