/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Computes the power of a number using recursion
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    long result;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    if (p % 2 == 0) {
        int half = my_compute_power_rec(nb, p / 2);
        result = (long)half * half;
    } else {
        result = (long)nb * my_compute_power_rec(nb, p - 1);
    }
    if (my_overflow_check((void *)(size_t)result, sizeof(int)))
        return 0;
    return (int)result;
}
