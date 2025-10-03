/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a string contains only numeric characters
*/

int my_str_isnum(char const *str)
{
    if (!str || !*str)
        return 0;
    for (; *str; str++) {
        if (*str < '0' || *str > '9')
            return 0;
    }
    return 1;
}
