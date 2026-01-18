/*
** EPITECH PROJECT, 2025
** My Library - Garbage Collector
** File description:
** Simple garbage collector implementation with explicit global state
*/

#include "../../include/my.h"

#ifndef NO_MALLOC

/**
 * gc_malloc - Allocate memory and track it in the garbage collector
 * @size: Size of memory to allocate
 *
 * Return: Pointer to allocated memory, or NULL on failure
 */
void *gc_malloc(size_t size)
{
    gc_node_t *new_node;
    void *ptr;

    if (size == 0)
        return (NULL);
    ptr = malloc(size);
    if (!ptr)
        return (NULL);
    new_node = malloc(sizeof(gc_node_t));
    if (!new_node) {
        free(ptr);
        return (NULL);
    }
    new_node->ptr = ptr;
    new_node->next = g_gc.head;
    g_gc.head = new_node;
    return (ptr);
}

/**
 * gc_free - Free a specific pointer tracked by the garbage collector
 * @ptr: Pointer to free
 *
 * Return: 0 on success, -1 if pointer not found in GC
 */
int gc_free(void *ptr)
{
    gc_node_t **indirect;
    gc_node_t *tmp;

    if (!ptr)
        return (0);
    indirect = &g_gc.head;
    while (*indirect) {
        if ((*indirect)->ptr == ptr) {
            tmp = *indirect;
            *indirect = (*indirect)->next;
            free(ptr);
            free(tmp);
            return (0);
        }
        indirect = &(*indirect)->next;
    }
    return (-1);
}

/**
 * gc_clean - Free all tracked pointers and clean up the garbage collector
 *
 * Return: 0 on success
 */
int gc_clean(void)
{
    gc_node_t *current;
    gc_node_t *next;

    current = g_gc.head;
    while (current) {
        next = current->next;
        if (current->ptr)
            free(current->ptr);
        free(current);
        current = next;
    }
    g_gc.head = NULL;
    return (0);
}

#endif /* !NO_MALLOC */
