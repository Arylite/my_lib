/*
** EPITECH PROJECT, 2025
** Libmy - my_showstr.c
** File description:
** Displays a string with non-printable characters in hexadecimal
*/

#include "my.h"

int my_showstr(char const *str)
{
    while (*str != '\0') {
        if (*str < 32 || *str > 126) {
            my_putnbr_base(*str, "0123456789abcdef");
        } else {
            my_putchar(*str);
        }
        str++;
    }
    return 0;
}
