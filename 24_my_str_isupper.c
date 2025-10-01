/*
** EPITECH PROJECT, 2025
** Libmy - my_str_isupper.c
** File description:
** Checks if a string contains only uppercase characters
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    while (*str != '\0') {
        if (*str < 65 || *str > 90)
            return 0;
        str++;
    }
    return 1;
}
