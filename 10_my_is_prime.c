/*
** EPITECH PROJECT, 2025
** Libmy - my_is_prime.c
** File description:
** Checks if a number is prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    int sr;

    if (my_overflow_check((void *)(size_t)nb))
        return 0;
    sr = my_compute_square_root(nb);
    if (nb <= 1)
        return 0;
    for (int i = 2; i <= nb / 2; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
