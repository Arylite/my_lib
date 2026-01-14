/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Printf handlers for basic types
*/

#include "my.h"
#include "printf_types.h"

int print_char(fmt_spec_t *spec, va_list args)
{
    char c = va_arg(args, int);
    int count = 0;

    if (!spec->left_align && spec->width > 1)
        count += print_padding(spec->width - 1, ' ');
    my_putchar(c);
    count++;
    if (spec->left_align && spec->width > 1)
        count += print_padding(spec->width - 1, ' ');
    return count;
}

int print_string(fmt_spec_t *spec, va_list args)
{
    char *str = va_arg(args, char *);
    int len = str ? my_strlen(str) : 6;
    int count = 0;

    if (!str)
        str = "(null)";
    if (spec->has_precision && spec->precision < len)
        len = spec->precision;
    if (!spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    for (int i = 0; i < len; i++)
        my_putchar(str[i]);
    count += len;
    if (spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    return count;
}
