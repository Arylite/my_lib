/*
** EPITECH PROJECT, 2025
** Libmy - my_sort_int_array.c
** File description:
** Sorts an array of integers
*/

#include "my.h"

void my_sort_int_if(int *a, int *b)
{
    if (*a < *b){
        my_swap(a, b);
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= (size - 1); j++){
            my_sort_int_if(&array[j], &array[j + 1]);
        }
    }
}
