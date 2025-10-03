/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Swaps the values of two integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}
