/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a number is negative or non-negative and prints 'N' or 'P'
*/

#include <unistd.h>

int my_isneg(int n)
{
    if ((n > 0) || (n == 0)) {
        ssize_t __w = write(1, "P", 1);
        (void)__w;
    } else if (n < 0) {
        ssize_t __w = write(1, "N", 1);
        (void)__w;
    }
    return 0;
}
