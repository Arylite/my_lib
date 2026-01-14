/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Printf integer handlers
*/

#include "my.h"
#include "printf_types.h"

static long long get_int_arg(fmt_spec_t *spec, va_list args)
{
    if (spec->length == 'L')
        return va_arg(args, long long);
    if (spec->length == 'l')
        return va_arg(args, long);
    if (spec->length == 'H')
        return (signed char)va_arg(args, int);
    if (spec->length == 'h')
        return (short)va_arg(args, int);
    return va_arg(args, int);
}

static int print_sign(long long n, fmt_spec_t *spec)
{
    if (n < 0) {
        my_putchar('-');
        return 1;
    }
    if (spec->show_sign) {
        my_putchar('+');
        return 1;
    }
    if (spec->space) {
        my_putchar(' ');
        return 1;
    }
    return 0;
}

static int calc_int_len(long long n, fmt_spec_t *s)
{
    unsigned long long un = n < 0 ? -n : n;
    int len = count_digits(un, 10);
    int sign = (n < 0 || s->show_sign || s->space) ? 1 : 0;

    if (s->has_precision && s->precision > len)
        len = s->precision;
    return len + sign;
}

static int print_int_value(long long n, fmt_spec_t *s)
{
    unsigned long long un = n < 0 ? -n : n;
    int digs = count_digits(un, 10);
    int count = print_sign(n, s);

    if (s->has_precision)
        count += print_padding(s->precision - digs, '0');
    count += print_nbr_base(un, "0123456789");
    return count;
}

int print_int(fmt_spec_t *spec, va_list args)
{
    long long n = get_int_arg(spec, args);
    int len = calc_int_len(n, spec);
    int count = 0;
    char pad = (spec->zero_pad && !spec->has_precision) ? '0' : ' ';

    if (spec->zero_pad && !spec->has_precision && !spec->left_align)
        count += print_sign(n, spec);
    if (!spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, pad);
    if (!spec->zero_pad || spec->has_precision || spec->left_align)
        count += print_int_value(n, spec);
    else
        count += print_nbr_base(n < 0 ? -n : n, "0123456789");
    if (spec->left_align && spec->width > len)
        count += print_padding(spec->width - len, ' ');
    return count;
}
