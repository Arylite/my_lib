/*
** EPITECH PROJECT, 2025
** Libmy - my_strncmp.c
** File description:
** Compares two strings up to n characters
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    if (n <= 0)
        return 0;
    while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (i == n)
        return 0;
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
