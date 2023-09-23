#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - swaps 2 int in an array.
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
 * hoare_partition - order a subset of an array of int 
 * just like the hoare partition scheme.
 * @array: the int array.
 * @size: array size.
 * @left: start index of subset to order.
 * @right: end index of subset to order.
 *
 * Return: last index in partition
 *
 * Description: with last element in partition as the pivot,
 * print array after each swap of 2 elements.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - use quicksort algorithm recursely.
 * @array: int array to sort.
 * @size: array size.
 * @left: start index of array partition to order.
 * @right: end index of array partition to order.
 *
 * Description: use of hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - sorts array of int in asc order 
 * using  quicksort algorithm.
 * @array: int array.
 * @size: array size.
 *
 * Description: using hoare partition scheme. prints
 * array after each swap of 2 elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}