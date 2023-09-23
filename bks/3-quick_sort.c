#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swap 2 int in an array.
 * @a: 1st int to swap.
 * @b: 2nd int to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - orders subset of int array using 
 * lomuto partition scheme (pivot as last element).
 * @array: int array.
 * @size: array size.
 * @left: start index of subset to order.
 * @right: end index of subset to order.
 *
 * Return: index of final partition.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - quicksort algorithm through recursion.
 * @array: int array to sort.
 * @size: array size.
 * @left: start index of array partition to order.
 * @right: end index of array partition to order.
 *
 * Description: Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - array of int in asc order using quicksort algorithm.
 * @array: int array.
 * @size: array size.
 *
 * Description: use of Lomuto partition scheme 
 * to print the array after each swap of 2 elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
