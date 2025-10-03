/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Unit tests for math functions
*/

#include <criterion/criterion.h>
#include "my.h"

Test(str_isalpha, basic)
{
    cr_assert_eq(my_str_isalpha("abc"), 1);
    cr_assert_eq(my_str_isalpha("abc123"), 0);
    cr_assert_eq(my_str_isalpha(""), 1);
    cr_assert_eq(my_str_isalpha("ABC"), 1);
    cr_assert_eq(my_str_isalpha("A B"), 0);
}

Test(str_isnum, basic)
{
    cr_assert_eq(my_str_isnum("123"), 1);
    cr_assert_eq(my_str_isnum("12a3"), 0);
    cr_assert_eq(my_str_isnum(""), 1);
    cr_assert_eq(my_str_isnum("0"), 1);
    cr_assert_eq(my_str_isnum("-123"), 0);
}

Test(str_isprintable, basic)
{
    cr_assert_eq(my_str_isprintable("abc"), 1);
    cr_assert_eq(my_str_isprintable("abc\n"), 0);
    cr_assert_eq(my_str_isprintable(""), 1);
    cr_assert_eq(my_str_isprintable(" "), 1);
}

Test(str_isupper, basic)
{
    cr_assert_eq(my_str_isupper("ABC"), 1);
    cr_assert_eq(my_str_isupper("AbC"), 0);
    cr_assert_eq(my_str_isupper(""), 1);
    cr_assert_eq(my_str_isupper("A B"), 0);
}

Test(str_islower, basic)
{
    cr_assert_eq(my_str_islower("abc"), 1);
    cr_assert_eq(my_str_islower("aBc"), 0);
    cr_assert_eq(my_str_islower(""), 1);
    cr_assert_eq(my_str_islower("a b"), 0);
}

Test(strcapitalize, basic)
{
    char str1[] = "hello world";
    char str2[] = "42epitech is cool";
    char str3[] = "";
    cr_assert_str_eq(my_strcapitalize(str1), "Hello World");
    cr_assert_str_eq(my_strcapitalize(str2), "42epitech Is Cool");
    cr_assert_str_eq(my_strcapitalize(str3), "");
}
