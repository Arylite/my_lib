/*
** EPITECH PROJECT, 2025
** Libmy - my_strncpy.c
** File description:
** Copies n characters from a string
*/

#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int compt;
    int lenght_dest = my_strlen(dest);

    for (compt = 0; src[compt] != '\0' && compt < n; compt++) {
        dest[compt] = src[compt];
    }
    while (compt < lenght_dest) {
        compt++;
        dest[compt] = '\0';
    }
    return dest;
}
