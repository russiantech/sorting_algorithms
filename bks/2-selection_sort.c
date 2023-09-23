#include "sort.h"

/**
 * swap_ints - swap 2 int in an array.
 * @a: 1st swappable int.
 * @b: 2nd swappable int.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - array of int in asc order 
 * using selection sort algorithm.
 * @array: int array
 * @size: array size
 *
 * Description: print an array after each swap
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
