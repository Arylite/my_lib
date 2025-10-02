/*
** EPITECH PROJECT, 2025
** Libmy - my_strcat.c
** File description:
** Concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    char *d = dest;
    while (*d) d++;
    while ((*d++ = *src++));
    return dest;
}
