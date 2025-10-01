/*
** EPITECH PROJECT, 2025
** Libmy - my_find_prime_sup.c
** File description:
** Finds the smallest prime number greater than or equal to the given number.
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int count;

    if (my_overflow_check((void *)(size_t)nb))
        return 84;
    for (count = nb; count <= 2147483647; count++) {
        if (my_is_prime(count))
            return (count);
    }
    return -1;
}
