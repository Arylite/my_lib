/*
** EPITECH PROJECT, 2025
** Libmy - Utility
** File description:
** Check for overflow in signed types
*/

#include <stdlib.h>
#include <stdbool.h>

bool my_overflow_check(void *something, size_t type_size)
{
    switch (type_size) {
        case sizeof(char):
            return (*(char *)something < 0);
        case sizeof(short):
            return (*(short *)something < 0);
        case sizeof(int):
            return (*(int *)something < 0);
        case sizeof(long):
            return (*(long *)something < 0);
        default:
            return false;
    }
}
