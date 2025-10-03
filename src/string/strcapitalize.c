/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Capitalizes the first letter of each word in a string
*/

#include "my.h"
#include <ctype.h>

static void capitalize_char(char *c, int new_word)
{
    if (new_word) {
        if (*c >= 'a' && *c <= 'z')
            *c -= 32;
    } else {
        if (*c >= 'A' && *c <= 'Z')
            *c += 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int new_word = 1;

    while (str[i] != '\0') {
        if (isalpha(str[i]) || isdigit(str[i])) {
            capitalize_char(&str[i], new_word);
            new_word = 0;
        } else {
            new_word = 1;
        }
        i++;
    }
    return str;
}
