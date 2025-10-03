/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Reverses a string
*/

/* Reverses a string */

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp;
    int j = len - 1;

    for (int i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return str;
}
