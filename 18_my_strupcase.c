/*
** EPITECH PROJECT, 2025
** Libmy - my_strupcase.c
** File description:
** Converts a string to uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    char *orig = str;
    int lenght = my_strlen(str);

    for (int i = 0; i < lenght; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return orig;
}
