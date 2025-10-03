/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Computes the power of a number using recursion
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    long result = nb;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    for (int i = 1; i < p; i++) {
        result *= nb;
        if (result > 2147483647L || result < -2147483648L)
            return 0;
    }
    return (int)result;
}
