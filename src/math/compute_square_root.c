/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Computes the approximate square root of a number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 0)
        return 0;
    while (i * i <= nb)
        i++;
    return i - 1;
}
