/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Outputs a string to the standard output
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    ssize_t __w = write(1, str, my_strlen(str));
    (void)__w;
    return 0;
}
