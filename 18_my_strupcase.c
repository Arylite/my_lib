/*
** EPITECH PROJECT, 2025
** Libmy - my_strupcase.c
** File description:
** Converts a string to uppercase
*/

char *my_strupcase(char *str)
{
    for (char *p = str; *p; ++p) {
        if (*p >= 'a' && *p <= 'z')
            *p -= 32;
    }
    return str;
}
