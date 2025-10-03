/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    char *d = dest;

    while (*d)
        d++;
    while (*src) {
        d++;
        src++;
        *d = *src;
    }
    *d = '\0';
    return dest;
}
