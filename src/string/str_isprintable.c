/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a string contains only printable characters
*/

int my_str_isprintable(char const *str)
{
    if (!str || !*str)
        return 1;
    for (; *str; str++)
        if ((unsigned char) *str < 32 || (unsigned char) *str > 126)
            return 0;
    return 1;
}
