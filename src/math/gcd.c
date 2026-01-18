/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Calculates the factorial of a number
*/

#include "my.h"

int gcd(int a, int b)
{
    int temp = 0;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a < 0 ? -a : a;
}
