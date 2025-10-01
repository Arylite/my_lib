/*
** EPITECH PROJECT, 2025
** Libmy - my_str_isnum.c
** File description:
** Checks if a string contains only numeric characters
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    while (*str != '\0') {
        if (*str < 48 || *str > 57)
            return 0;
        str++;
    }
    return 1;
}
