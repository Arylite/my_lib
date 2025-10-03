/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a string contains only alphabetic characters
*/

#include <stddef.h>

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return 0;
    if (*str == '\0')
        return 1;
    for (int i = 0; str[i]; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] >= 'a' && str[i] <= 'z')))
            return 0;
    }
    return 1;
}
