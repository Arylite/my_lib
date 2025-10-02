/*
** EPITECH PROJECT, 2025
** Libmy - my_compute_square_root.c
** File description:
** Computes the approximate square root of a number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int count;
    int sr = 0;

    if (my_overflow_check((void *)(size_t)nb))
        return 84;
    nb = nb / 1;
    for (int count = 1; nb > 0; count += 2){
        nb -= count;
        sr++;
    }
    if (nb < 0)
        return 0;
    return sr;
}
