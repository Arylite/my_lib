/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Compares two strings, return the difference
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char) *s1 - (unsigned char) *s2;
}
