/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Outputs a character to the standard output
*/

#include <unistd.h>

void my_putchar(char c)
{
    ssize_t __w = write(1, &c, 1);

    (void)__w;
}
