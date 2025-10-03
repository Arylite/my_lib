/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a string contains only uppercase characters
*/

int my_str_isupper(char const *str)
{
    if (!str)
        return 0;
    if (*str == '\0')
        return 1;
    for (; *str; str++) {
        if (*str < 'A' || *str > 'Z')
            return 0;
    }
    return 1;
}
