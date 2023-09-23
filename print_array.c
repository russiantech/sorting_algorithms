#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - will print array of int
 *
 * @array: array in question
 * @size: num of elements of @array
 */

void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
