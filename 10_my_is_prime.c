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
    if (nb <= 1)
        return 0;
    if (nb == 2)
        return 1;
    if (nb % 2 == 0)
        return 0;
    sr = my_compute_square_root(nb);
    for (int i = 3; i <= sr; i += 2) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
