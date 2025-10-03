/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a string contains only lowercase characters
*/

int my_str_islower(char const *str)
{
    if (!str || !*str)
        return 0;
    for (; *str; str++) {
        if (*str < 'a' || *str > 'z')
            return 0;
    }
    return 1;
}
