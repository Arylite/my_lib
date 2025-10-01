/*
** EPITECH PROJECT, 2025
** Libmy - my_strstr.c
** File description:
** Finds the first occurrence of a substring in a string
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int len_to_find = my_strlen(to_find);

    if (len_to_find == 0)
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], to_find, len_to_find) == 0) {
            return &str[i];
        }
    }
    return 0;
}
