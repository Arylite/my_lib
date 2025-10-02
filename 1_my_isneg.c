/*
** EPITECH PROJECT, 2025
** Libmy - my_isneg.c
** File description:
** Checks if a number is negative or non-negative and prints 'N' or 'P'
*/

#include <unistd.h>

int my_isneg(int n)
{
    char c;

    if ((n > 0) || (n == 0)) {
        write(1, "P", 1);
    } else if (n < 0) {
        write(1, "N", 1);
    }
    return 0;
}
