/*
** EPITECH PROJECT, 2025
** Libmy - my_str_isalpha.c
** File description:
** Checks if a string contains only alphabetic characters
*/

#include "my.h"

int is_alpha_char(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int not_a_bypass(char const *str, int count)
{
    if (!is_alpha_char(str[count]))
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    int lenght = my_strlen(str);
    int count;

    for (count = 0; count < lenght; count++) {
        if (not_a_bypass(str, count))
            return 0;
    }
    return 1;
}
