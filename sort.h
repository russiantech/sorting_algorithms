#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Compares direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - enumerate bool values.
 * @false: === 0.
 * @true: === 1.
 */

typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - linked-list-node(doubly)
 *
 * @n: int saved in the node
 * @prev: Points to previous elemeent in listint_s
 * @next: points to next element in listint_s
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helpers */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algos */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
#endif /* SORT_H */
