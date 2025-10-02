/*
** EPITECH PROJECT, 2025
** Libmy - my_showmem.c
** File description:
** Displays memory content in a formatted way
*/

#include "my.h"

int my_showmem(const char *str, int size)
{
    int i, j;
    char buf[12];

    for (i = 0; i < size; i += 16) {
        my_putnbr_base(i, "0123456789abcdef");
        my_putstr(": ");
        for (j = 0; j < 16; j++) {
            if (i + j < size) {
                unsigned char val = (unsigned char)str[i + j];
                if (val < 16)
                    my_putstr("0");
                my_putnbr_base(val, "0123456789abcdef");
            } else {
                my_putstr("  ");
            }
            if (j % 2 == 1)
                my_putstr(" ");
        }
        for (j = 0; j < 16 && i + j < size; j++) {
            char c = str[i + j];
            my_putchar(my_isprint((unsigned char)c) ? c : '.');
        }
        my_putchar('\n');
    }
    return 0;
}
