/*
** EPITECH PROJECT, 2025
** Libmy - my_strncmp.c
** File description:
** Compares two strings up to n characters
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}
