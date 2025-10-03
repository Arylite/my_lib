/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Copies a string into another
*/
char *my_strcpy(char *dest, char const *src)
{
    char *d = dest;

    while (*src != '\0') {
        d++;
        src++;
        *d = *src;
    }
    *d = '\0';
    return dest;
}
