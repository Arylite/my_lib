/*
** EPITECH PROJECT, 2025
** Libmy - my_str_isprintable.c
** File description:
** Checks if a string contains only printable characters
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    while (*str != '\0') {
        if (*str < 32 || *str > 126)
            return 0;
        str++;
    }
    return 1;
}
