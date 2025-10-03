/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Concatenates two strings with a limit on the number of characters
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    char *ptr = dest;

    while (*ptr)
        ptr++;
    for (int i = 0; i < nb && src[i]; i++) {
        ptr++;
        *ptr = src[i];
    }
    *ptr = '\0';
    return dest;
}
