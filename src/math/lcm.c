/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Calculates the least common multiple of two numbers
*/

#include "my.h"

int lcm(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    return (ABS(a) / gcd(ABS(a), ABS(b))) * ABS(b);
}
