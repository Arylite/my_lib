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
    #include <stdarg.h>

    /* Useful macros */
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define CEIL(x) ((x) == (int)(x) ? (x) : (int)(x) + 1)
    #define FLOOR(x) ((x) == (int)(x) ? (x) : (int)(x))
    #define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))
    #define IS_EVEN(x) ((x)%2 == 0)
    #define IS_ODD(x) ((x)%2 != 0)
    #define UNUSED __attribute__((unused))

typedef struct printf_node_s {
    char specifier;
    size_t (*handler)(va_list args);
} printf_node_t;

typedef struct gc_node_s {
    void *ptr;
    struct gc_node_s *next;
} gc_node_t;

typedef struct gc_s {
    gc_node_t *head;
} gc_t;

/* Garbage collector global state */
extern gc_t g_gc;

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

/* Compares two strings in a case-insensitive manner */
int my_strcmp_insensitive(char const *s1, char const *s2);

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

/* Splits a string into an array of words (requires malloc) */
    #ifndef NO_MALLOC
char **str_to_word_array(const char *str);
    #endif

/* Duplicates a string (requires malloc) */
    #ifndef NO_MALLOC
char *strdup(const char *str);
    #endif

/* Printf implementation */
int my_printf(const char *format, ...);

/* Garbage Collector (requires malloc) */
    #ifndef NO_MALLOC

/* Allocate memory and track it in the garbage collector */
void *gc_malloc(size_t size);

/* Free a specific pointer tracked by the garbage collector */
int gc_free(void *ptr);

/* Free all tracked pointers and clean up the garbage collector */
int gc_clean(void);

void *my_calloc(size_t nmemb, size_t size);

    #endif

/* Set a block of memory to a specific value */
void *my_memset(void *pointer, int value, size_t count);

/* Compare two memory areas */
int my_memcmp(const void *pointer1, const void *pointer2, size_t size);

/* Copy memory area */
void *my_memcpy(void *dest, const void *src, size_t n);

/* Computes the factorial of a number */
long long factorial(int n);

/* Computes the greatest common divisor of two numbers */
int gcd(int a, int b);

/* Computes the least common multiple of two numbers */
int lcm(int a, int b);

/* Duplicates an array of any type */
void *array_dup(void *array);

/* Return the size of an array of any type */
size_t array_size(void *array);

/* Compares two arrays of any type with a custom comparator */
size_t array_cmp(void *array1, void *array2,
    size_t (*comparator)(void *, void *));

/* Sorts an array of any type with a custom comparator */
size_t array_sort(void *array,
    size_t (*comparator)(void *, void *));

char **my_array_from_strings(char *strings[]);

#endif /* MY_H_ */
