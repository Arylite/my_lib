/*
** EPITECH PROJECT, 2025
** Libmy - my_putstr.c
** File description:
** Outputs a string to the standard output
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
