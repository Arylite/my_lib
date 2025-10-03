/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Gets an integer from a string
*/

int my_getnbr(char const *str)
{
    int sign = 1;
    int result = 0;

    while (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -sign;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
