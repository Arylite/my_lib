/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Displays a string and non-printable characters in a specific format
*/

#include "my.h"

static void print_non_printable(unsigned char c)
{
    my_putchar('\\');
    if (c < 16)
        my_putchar('0');
    my_putnbr_base(c, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    unsigned char c;

    if (str == NULL)
        return 84;
    for (; *str; str++) {
        c = (unsigned char)*str;
        if (c < 32 || c > 126)
            print_non_printable(c);
        else
            my_putchar(c);
    }
    return 0;
}
