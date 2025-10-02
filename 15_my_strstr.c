/*
** EPITECH PROJECT, 2025
** Libmy - my_strstr.c
** File description:
** Finds the first occurrence of a substring in a string
*/
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    if (!*to_find)
        return str;
    for (; *str; str++) {
        char *s = str;
        char const *f = to_find;
        while (*s && *f && *s == *f) {
            s++;
            f++;
        }
        if (!*f)
            return (char *)str;
    }
    return NULL;
}
