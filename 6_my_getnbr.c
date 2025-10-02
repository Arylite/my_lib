/*
** EPITECH PROJECT, 2025
** Libmy - my_getnbr.c
** File description:
** Converts a string to an integer
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int sign = 1;
    int result = 0;

    while (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -sign;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
