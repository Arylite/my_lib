/*
** EPITECH PROJECT, 2025
** Libmy - my_strcpy.c
** File description:
** Copies a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}
