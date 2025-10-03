/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Displays memory content in a formatted way
*/

#include "my.h"

static void print_hex_byte(unsigned char val)
{
    if (val < 16)
        my_putchar('0');
    my_putnbr_base(val, "0123456789abcdef");
}

static void print_hex_line(const char *str, int start, int size)
{
    int j;

    for (j = 0; j < 16; j++) {
        if (start + j < size) {
            print_hex_byte((unsigned char)str[start + j]);
        } else {
            my_putstr("  ");
        }
        if (j % 2)
            my_putchar(' ');
    }
}

static void print_ascii_line(const char *str, int start, int size)
{
    int j;
    char c;

    for (j = 0; j < 16 && start + j < size; j++) {
        c = str[start + j];
        if (c >= 32 && c <= 126)
            my_putchar(c);
        else
            my_putchar('.');
    }
}

int my_showmem(const char *str, int size)
{
    for (int i = 0; i < size; i += 16) {
        my_putnbr_base(i, "0123456789abcdef");
        my_putstr(": ");
        print_hex_line(str, i, size);
        print_ascii_line(str, i, size);
        my_putchar('\n');
    }
    return 0;
}
