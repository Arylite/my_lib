/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Printf unsigned handlers
*/

#include "my.h"
#include "printf_types.h"

static unsigned long long get_uint_arg(fmt_spec_t *s, va_list a)
{
    if (s->length == 'L')
        return va_arg(a, unsigned long long);
    if (s->length == 'l')
        return va_arg(a, unsigned long);
    if (s->length == 'H')
        return (unsigned char)va_arg(a, unsigned int);
    if (s->length == 'h')
        return (unsigned short)va_arg(a, unsigned int);
    return va_arg(a, unsigned int);
}

static int print_prefix(fmt_spec_t *s, char *base)
{
    (void)base;
    if (!s->alternate)
        return 0;
    if (s->specifier == 'o') {
        my_putchar('0');
        return 1;
    }
    if (s->specifier == 'x' || s->specifier == 'X') {
        my_putchar('0');
        my_putchar(s->specifier);
        return 2;
    }
    return 0;
}

int print_unsigned(fmt_spec_t *spec, va_list args)
{
    unsigned long long n = get_uint_arg(spec, args);
    int len = count_digits(n, 10);
    int count = 0;

    if (spec->has_precision && spec->precision > len)
        len = spec->precision;
    if (!spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    if (spec->has_precision)
        count += print_padding(spec->precision - count_digits(n, 10), '0');
    count += print_nbr_base(n, "0123456789");
    if (spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    return count;
}

int print_hex(fmt_spec_t *spec, va_list args)
{
    unsigned long long n = get_uint_arg(spec, args);
    char *base = (spec->specifier == 'X') ? "0123456789ABCDEF" :
        "0123456789abcdef";
    int len = count_digits(n, 16) + (spec->alternate && n ? 2 : 0);
    int count = 0;

    if (!spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    if (n != 0)
        count += print_prefix(spec, base);
    count += print_nbr_base(n, base);
    if (spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    return count;
}

int print_octal(fmt_spec_t *spec, va_list args)
{
    unsigned long long n = get_uint_arg(spec, args);
    int len = count_digits(n, 8) + (spec->alternate && n ? 1 : 0);
    int count = 0;

    if (!spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    if (n != 0)
        count += print_prefix(spec, "01234567");
    count += print_nbr_base(n, "01234567");
    if (spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    return count;
}

int print_pointer(fmt_spec_t *spec, va_list args)
{
    unsigned long long ptr = (unsigned long long)va_arg(args, void *);
    int len = count_digits(ptr, 16) + 2;
    int count = 0;

    if (!spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    my_putstr("0x");
    count += 2 + print_nbr_base(ptr, "0123456789abcdef");
    if (spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    return count;
}
