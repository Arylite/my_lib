/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Displays a string with non-printable characters in hexadecimal
*/

#include "my.h"

int my_showstr(char const *str)
{
    for (; *str; str++) {
        if ((unsigned char)*str < 32 || (unsigned char)*str > 126) {
            my_putchar('\\');
            if ((unsigned char)*str < 16)
                my_putchar('0');
            my_putnbr_base((unsigned char)*str, "0123456789abcdef");
        } else {
            my_putchar(*str);
        }
    }
    return 0;
}
