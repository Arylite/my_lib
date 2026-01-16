/*
** EPITECH PROJECT, 2025
** My Library
** File description:
** Checks if a string contains only uppercase characters
*/

#include <stdlib.h>

#ifndef NO_MALLOC

static int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

static int skip_spaces(const char *str, int i)
{
    while (str[i] && is_space(str[i]))
        i++;
    return i;
}

static int word_len(const char *str, int i)
{
    int len = 0;

    while (str[i] && !is_space(str[i])) {
        len++;
        i++;
    }
    return len;
}

static char *copy_word(const char *str, int start)
{
    int i = 0;
    int len = word_len(str, start);
    char *word = malloc(sizeof(char) * (len + 1));

    if (!word)
        return NULL;
    while (i < len) {
        word[i] = str[start + i];
        i++;
    }
    word[i] = '\0';
    return word;
}

static int count_words(const char *str)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        i = skip_spaces(str, i);
        if (!str[i])
            break;
        count++;
        i += word_len(str, i);
    }
    return count;
}

char **str_to_word_array(const char *str)
{
    int i = 0;
    int k = 0;
    int words = count_words(str);
    char **array = malloc(sizeof(char *) * (words + 1));

    if (!array)
        return NULL;
    while (k < words) {
        i = skip_spaces(str, i);
        array[k] = copy_word(str, i);
        if (!array[k])
            return NULL;
        i += word_len(str, i);
        k++;
    }
    array[k] = NULL;
    return array;
}

#endif /* NO_MALLOC */
