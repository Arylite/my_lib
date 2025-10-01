/*
** EPITECH PROJECT, 2025
** Libmy - my_strcat.c
** File description:
** Concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *dest_end = dest;

    while (*dest_end != '\0') {
        dest_end++;
    }
    while (*src != '\0') {
        *dest_end = *src;
        dest_end++;
        src++;
    }
    *dest_end = '\0';
    return dest;
}
