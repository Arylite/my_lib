/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Printf utilities
*/

#include "my.h"

int print_padding(int width, char pad)
{
    int count = 0;

    while (width > 0) {
        my_putchar(pad);
        count++;
        width--;
    }
    return count;
}

int count_digits(unsigned long long n, int base)
{
    int count = 1;

    while (n >= (unsigned long long)base) {
        n /= base;
        count++;
    }
    return count;
}

static void print_nbr_rec(unsigned long long n, char *base)
{
    int base_len = my_strlen(base);

    if (n >= (unsigned long long)base_len)
        print_nbr_rec(n / base_len, base);
    my_putchar(base[n % base_len]);
}

int print_nbr_base(unsigned long long n, char *base)
{
    int len = count_digits(n, my_strlen(base));

    print_nbr_rec(n, base);
    return len;
}
