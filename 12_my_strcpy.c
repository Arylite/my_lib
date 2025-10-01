/*
** EPITECH PROJECT, 2025
** Libmy - my_strcpy.c
** File description:
** Copies a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int compt;

    for (compt = 0; src[compt] != '\0'; compt++) {
        dest[compt] = src[compt];
    }
    dest[compt] = '\0';
    return dest;
}
