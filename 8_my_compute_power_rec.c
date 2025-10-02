/*
** EPITECH PROJECT, 2025
** Libmy - my_compute_power_rec.c
** File description:
** Recursive function that returns the value of nb raised to the power of p
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int half = my_compute_power_rec(nb, p / 2);
    long result;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    if (p % 2 == 0)
        result = (long)half * half;
    else
        result = (long)half * half * nb;
    if (my_overflow_check((void *)(size_t)result))
        return 0;
    return (int)result;
}
