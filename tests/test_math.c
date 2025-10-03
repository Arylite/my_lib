/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Unit tests for math functions
*/

#include <criterion/criterion.h>
#include "my.h"

Test(compute_power_rec, basic)
{
    cr_assert_eq(my_compute_power_rec(2, 3), 8);
    cr_assert_eq(my_compute_power_rec(5, 0), 1);
    cr_assert_eq(my_compute_power_rec(0, 5), 0);
    cr_assert_eq(my_compute_power_rec(1, 100), 1);
}

Test(compute_square_root, basic)
{
    cr_assert_eq(my_compute_square_root(9), 3);
    cr_assert_eq(my_compute_square_root(16), 4);
    cr_assert_eq(my_compute_square_root(2), 1);
    cr_assert_eq(my_compute_square_root(0), 0);
}

Test(find_prime_sup, basic)
{
    cr_assert_eq(my_find_prime_sup(10), 11);
    cr_assert_eq(my_find_prime_sup(17), 17);
    cr_assert_eq(my_find_prime_sup(1), 2);
}

Test(is_prime, basic)
{
    cr_assert_eq(my_is_prime(2), 1);
    cr_assert_eq(my_is_prime(17), 1);
    cr_assert_eq(my_is_prime(18), 0);
    cr_assert_eq(my_is_prime(1), 0);
}

Test(sort_int_array, basic)
{
    int arr[] = {5, 2, 9, 1};
    my_sort_int_array(arr, 4);
    cr_assert_eq(arr[0], 1);
    cr_assert_eq(arr[1], 2);
    cr_assert_eq(arr[2], 5);
    cr_assert_eq(arr[3], 9);
}

Test(swap, basic)
{
    int a = 5;
    int b = 10;
    my_swap(&a, &b);
    cr_assert_eq(a, 10);
    cr_assert_eq(b, 5);
}
