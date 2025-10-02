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
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        my_swap(&str[i], &str[j]);
    }
    return str;
}
