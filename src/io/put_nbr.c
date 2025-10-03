/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Outputs an integer to the standard output
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_put_nbr(nb / 10);
            my_putchar('8');
            return 0;
        }
        nb = -nb;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return 0;
}
