/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Outputs a number in a given base to the standard output
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = my_strlen(base);
    unsigned int unbr;

    if (base_len < 2)
        return 0;
    if (nbr < 0) {
        my_putchar('-');
        unbr = (unsigned int)(-nbr);
    } else {
        unbr = (unsigned int)nbr;
    }
    if (unbr >= (unsigned int)base_len) {
        my_putnbr_base((int)(unbr / base_len), base);
    }
    my_putchar(base[unbr % base_len]);
    return 0;
}
