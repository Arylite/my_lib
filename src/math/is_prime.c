/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a number is prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    int sr = 1;

    if (nb <= 1)
        return 0;
    if (nb == 2)
        return 1;
    if (nb % 2 == 0)
        return 0;
    while (sr * sr <= nb)
        sr++;
    sr--;
    for (int i = 3; i <= sr; i += 2) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
