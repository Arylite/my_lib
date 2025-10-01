/*
** EPITECH PROJECT, 2025
** Libmy - my_strcapitalize.c
** File description:
** Capitalizes the first letter of each word in a string
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;
    int new_word = 1;

    while (str[i] != '\0') {
        if (my_isalpha(str[i])) {
            if (new_word && my_islower(&str[i])) {
                str[i] = *my_strupcase(&str[i]);
            } else if (!new_word && my_isupper(&str[i])) {
                str[i] = *my_strlowcase(&str[i]);
            }
            new_word = 0;
        } else if (my_isdigit(&str[i])) {
            new_word = 0;
        } else {
            new_word = 1;
        }
        i++;
    }
    return str;
}
