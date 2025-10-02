/*
** EPITECH PROJECT, 2025
** Libmy - my_str_isupper.c
** File description:
** Checks if a string contains only uppercase characters
*/

int my_str_isupper(char const *str)
{
    if (!str || !*str)
        return 0;
    for (; *str; str++) {
        if (*str < 'A' || *str > 'Z')
            return 0;
    }
    return 1;
}
