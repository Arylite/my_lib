/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** C99 printf implementation
*/

#include "my.h"
#include "printf_types.h"

static int process_char(const char **fmt, int *count)
{
    my_putchar(**fmt);
    (*fmt)++;
    (*count)++;
    return 1;
}

static int process_percent(const char **fmt, int *count)
{
    my_putchar('%');
    (*fmt) += 2;
    (*count)++;
    return 1;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (!format)
        return -1;
    va_start(args, format);
    while (*format) {
        if (*format != '%') {
            process_char(&format, &count);
            continue;
        }
        if (*(format + 1) == '%') {
            process_percent(&format, &count);
            continue;
        }
        count += handle_format(&format, args);
    }
    va_end(args);
    return count;
}
