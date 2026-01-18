/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Calculates the factorial of a number
*/

#include "my.h"

long long factorial(int n)
{
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
