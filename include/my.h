/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Header file for my library
*/
#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <limits.h>

    /* Useful macros */
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define UNUSED __attribute__((unused))

/* Function prototypes */

/* Outputs a character to the standard output */
void my_putchar(char c);

/* Checks if a number is negative or non-negative and prints 'N' or 'P' */
int my_isneg(int n);

/* Outputs an integer to the standard output */
int my_put_nbr(int nb);

/* Swaps the values of two integers */
void my_swap(int *a, int *b);

/* Outputs a string to the standard output */
int my_putstr(char const *str);

/* Counts the number of characters in a string */
int my_strlen(char const *str);

/* Converts a string to an integer */
int my_getnbr(char const *str);

/* Sorts an array of integers */
void my_sort_int_array(int *array, int size);

/* Recursive function that returns nb raised to the power of p */
int my_compute_power_rec(int nb, int p);

/* Computes the approximate square root of a number */
int my_compute_square_root(int nb);

/* Checks if a number is prime */
int my_is_prime(int nb);

/* Finds the smallest prime number greater than or equal to nb */
int my_find_prime_sup(int nb);

/* Copies a string into another */
char *my_strcpy(char *dest, char const *src);

/* Copies n characters from a string */
char *my_strncpy(char *dest, char const *src, int n);

/* Reverses a string */
char *my_revstr(char *str);

/* Finds the first occurrence of a substring in a string */
char *my_strstr(char *str, char const *to_find);

/* Compares two strings, returns the difference */
int my_strcmp(char const *s1, char const *s2);

/* Compares two strings up to n characters */
int my_strncmp(char const *s1, char const *s2, int n);

/* Converts a string to uppercase */
char *my_strupcase(char *str);

/* Converts a string to lowercase */
char *my_strlowcase(char *str);

/* Capitalizes the first letter of each word in a string */
char *my_strcapitalize(char *str);

/* Checks if a string contains only alphabetic characters */
int my_str_isalpha(char const *str);

/* Checks if a string contains only numeric characters */
int my_str_isnum(char const *str);

/* Checks if a string contains only lowercase characters */
int my_str_islower(char const *str);

/* Checks if a string contains only uppercase characters */
int my_str_isupper(char const *str);

/* Checks if a string contains only printable characters */
int my_str_isprintable(char const *str);

/* Displays a string with non-printable characters in hexadecimal */
int my_showstr(char const *str);

/* Displays memory content in a formatted way */
int my_showmem(const char *str, int size);

/* Concatenates two strings */
char *my_strcat(char *dest, char const *src);

/* Concatenates two strings with a limit on the number of characters */
char *my_strncat(char *dest, char const *src, int nb);

/* Converts and prints a number in a specified base */
int my_putnbr_base(int nbr, char const *base);

/* Check for overflow in signed types */
bool my_overflow_check(void *something, size_t type_size);

#endif /* MY_H_ */
