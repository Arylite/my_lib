/*
** EPITECH PROJECT, 2025
** Libmy - my_strncat.c
** File description:
** Concatenates two strings with a limit on the number of characters
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }
    while (nb > 0 && *src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
        nb--;
    }
    *ptr = '\0';
    return dest;
}
