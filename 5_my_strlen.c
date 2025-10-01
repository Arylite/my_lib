/*
** EPITECH PROJECT, 2025
** Libmy - my_strlen.c
** File description:
** Counts the number of characters in a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
