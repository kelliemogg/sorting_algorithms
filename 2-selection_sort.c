#include "sort.h"

/**
 * selection_sort - selection sort
 * description: sort an array of integers in ascending order
 * @array: array
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, tmp, min = 0;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		if (min != i)
			print_array(array, size);
	}
}
