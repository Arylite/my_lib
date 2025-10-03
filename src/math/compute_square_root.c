/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Computes the approximate square root of a number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int sr = 0;

    if (my_overflow_check((void *)(size_t)nb, sizeof(int)))
        return 84;
    nb = nb / 1;
    for (int odd = 1; nb > 0; odd += 2) {
        nb -= odd;
        sr++;
    }
    if (nb < 0)
        return 0;
    return sr;
}
