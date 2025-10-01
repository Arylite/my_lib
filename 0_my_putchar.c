/*
** EPITECH PROJECT, 2025
** Libmy - my_putchar.c
** File description:
** Outputs a character to the standard output
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
