/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Finds the smallest prime number greater than or equal to the given number. 
*/

#include <limits.h>
#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        nb = 2;
    if (my_overflow_check((void *)(size_t)nb, sizeof(int)))
        return 84;
    while (nb <= INT_MAX) {
        if (my_is_prime(nb))
            return nb;
        nb += (nb == 2) ? 1 : 2;
    }
    return -1;
}
