/*
** EPITECH PROJECT, 2025
** Libmy - my_revstr.c
** File description:
** Reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    char junk;

    while (i < len / 2) {
        junk = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = junk;
        i++;
    }
    return str;
}
