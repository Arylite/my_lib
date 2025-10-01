/*
** EPITECH PROJECT, 2025
** Libmy - my_getnbr.c
** File description:
** Converts a string to an integer
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int compt = 0;
    int sign = 1;
    int result = 0;

    while (str[compt] == 45 || str[compt] == 43) {
        if (str[compt] == 45)
            sign = -sign;
        compt++;
    }
    while (str[compt] >= '0' && str[compt] <= '9') {
        result = result * 10 + (str[compt] - '0');
        compt++;
    }
    return result * sign;
}
