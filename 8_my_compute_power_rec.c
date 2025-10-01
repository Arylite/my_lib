/*
** EPITECH PROJECT, 2025
** Libmy - my_compute_power_rec.c
** File description:
** Recursive function that returns the value of nb raised to the power of p
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    long result;

    if (p < 0)
        return 0;
    if (my_overflow_check((void *)(size_t)nb)
        || my_overflow_check((void *)(size_t)p))
        return 0;
    if (p == 0)
        return 1;
    result = (long)nb * my_compute_power_rec(nb, p - 1);
    if (my_overflow_check((void *)(size_t)result))
        return 0;
    return (int)result;
}
