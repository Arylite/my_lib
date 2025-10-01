/*
** EPITECH PROJECT, 2025
** Libmy - my_str_islower.c
** File description:
** Checks if a string contains only lowercase characters
*/

#include "my.h"

int my_str_islower(char const *str)
{
    while (*str != '\0') {
        if (*str < 97 || *str > 122)
            return 0;
        str++;
    }
    return 1;
}
