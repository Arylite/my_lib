/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Capitalizes the first letter of each word in a string
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;
    int new_word = 1;

    while (str[i] != '\0') {
        if (my_str_isalpha(&str[i]) && new_word && my_str_islower(&str[i])) {
            str[i] -= 'a' - 'A';
        } else if (my_str_isalpha(&str[i]) && !new_word 
                && my_str_isupper(&str[i])) {
            str[i] += 'a' - 'A';
        }
        if (my_str_isalpha(&str[i]) || my_str_isnum(&str[i])) {
            new_word = 0;
        } else {
            new_word = 1;
        }
        i++;
    }
    return str;
}
