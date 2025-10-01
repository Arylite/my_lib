/*
** EPITECH PROJECT, 2025
** Libmy - my_putstr.c
** File description:
** Outputs a string to the standard output
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
