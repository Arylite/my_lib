/*
** EPITECH PROJECT, 2025
** Libmy - my_swap.c
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
