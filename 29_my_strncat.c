/*
** EPITECH PROJECT, 2025
** Libmy - my_strncat.c
** File description:
** Concatenates two strings with a limit on the number of characters
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    char *ptr = dest;

    while (*ptr)
        ptr++;
    for (int i = 0; i < nb && src[i]; i++)
        *ptr++ = src[i];
    *ptr = '\0';
    return dest;
}
