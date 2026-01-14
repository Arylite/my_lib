/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Printf internal types
*/

#ifndef PRINTF_TYPES_H_
    #define PRINTF_TYPES_H_
    #include <stdarg.h>

typedef struct {
    int left_align;
    int show_sign;
    int space;
    int alternate;
    int zero_pad;
    int width;
    int precision;
    int has_precision;
    char length;
    char specifier;
} fmt_spec_t;

int print_padding(int width, char pad);
int count_digits(unsigned long long n, int base);
int print_nbr_base(unsigned long long n, char *base);
int handle_format(const char **fmt, va_list args);
int print_char(fmt_spec_t *spec, va_list args);
int print_string(fmt_spec_t *spec, va_list args);
int print_int(fmt_spec_t *spec, va_list args);
int print_unsigned(fmt_spec_t *spec, va_list args);
int print_hex(fmt_spec_t *spec, va_list args);
int print_octal(fmt_spec_t *spec, va_list args);
int print_pointer(fmt_spec_t *spec, va_list args);

#endif /* PRINTF_TYPES_H_ */
