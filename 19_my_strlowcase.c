/*
** EPITECH PROJECT, 2025
** Libmy - my_strlowcase.c
** File description:
** Converts a string to lowercase
*/

char *my_strlowcase(char *str)
{
    for (char *p = str; *p; ++p)
        if ((unsigned char)*p >= 'A' && (unsigned char)*p <= 'Z')
            *p += 'a' - 'A';
    return str;
}
