/*
** EPITECH PROJECT, 2025
** Libmy - my_isneg.c
** File description:
** Checks if a number is negative or non-negative and prints 'N' or 'P'
*/

#include "my.h"

int my_isneg(int n)
{
    char c;

    if ((n > 0) || (n == 0)) {
        c = 'P';
        my_putchar(c);
    } else if (n < 0) {
        c = 'N';
        my_putchar(c);
    }
    return 0;
}
