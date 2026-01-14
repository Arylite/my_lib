/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Printf format parser
*/

#include "my.h"
#include "printf_types.h"

static void parse_flags(const char **fmt, fmt_spec_t *spec)
{
    while (**fmt == '-' || **fmt == '+' || **fmt == ' ' ||
        **fmt == '#' || **fmt == '0') {
        if (**fmt == '-')
            spec->left_align = 1;
        if (**fmt == '+')
            spec->show_sign = 1;
        if (**fmt == ' ')
            spec->space = 1;
        if (**fmt == '#')
            spec->alternate = 1;
        if (**fmt == '0')
            spec->zero_pad = 1;
        (*fmt)++;
    }
}

static void parse_width(const char **fmt, fmt_spec_t *spec)
{
    while (**fmt >= '0' && **fmt <= '9') {
        spec->width = spec->width * 10 + (**fmt - '0');
        (*fmt)++;
    }
}

static void parse_precision(const char **fmt, fmt_spec_t *s)
{
    if (**fmt != '.')
        return;
    (*fmt)++;
    s->has_precision = 1;
    s->precision = 0;
    while (**fmt >= '0' && **fmt <= '9') {
        s->precision = s->precision * 10 + (**fmt - '0');
        (*fmt)++;
    }
}

static void parse_length(const char **fmt, fmt_spec_t *spec)
{
    if (**fmt == 'l' || **fmt == 'h') {
        spec->length = **fmt;
        (*fmt)++;
        if (**fmt == spec->length) {
            spec->length = (spec->length == 'l') ? 'L' : 'H';
            (*fmt)++;
        }
    }
}

static void init_spec(fmt_spec_t *spec)
{
    spec->left_align = 0;
    spec->show_sign = 0;
    spec->space = 0;
    spec->alternate = 0;
    spec->zero_pad = 0;
    spec->width = 0;
    spec->precision = 0;
    spec->has_precision = 0;
    spec->length = 0;
    spec->specifier = 0;
}

static int handle_unknown(const char **fmt)
{
    my_putchar('%');
    my_putchar(**fmt);
    (*fmt)++;
    return 2;
}

static int dispatch_handler(const char **fmt, fmt_spec_t *s, va_list a)
{
    int (*handlers[])(fmt_spec_t *, va_list) = {
        print_char, print_string, print_int, print_int,
        print_unsigned, print_hex, print_hex, print_octal, print_pointer
    };
    const char specs[] = "csdiuxXop";

    for (int i = 0; specs[i]; i++) {
        if (specs[i] == s->specifier) {
            (*fmt)++;
            return handlers[i](s, a);
        }
    }
    return handle_unknown(fmt);
}

int handle_format(const char **fmt, va_list args)
{
    fmt_spec_t spec;

    init_spec(&spec);
    (*fmt)++;
    parse_flags(fmt, &spec);
    parse_width(fmt, &spec);
    parse_precision(fmt, &spec);
    parse_length(fmt, &spec);
    spec.specifier = **fmt;
    return dispatch_handler(fmt, &spec, args);
}
