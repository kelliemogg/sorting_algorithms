#include "sort.h"

/**
 * quick_sort - quick sort algorithm
 * description: sorts an array of ints in ascending order using the Quick
 * sort algorithm - includes the Lomuto partition scheme
 * @array: array of unsorted ints
 * @size: of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int j, i, swap, p;

	if (size <= 2)
	{
		return;
	}
	p = array[size - 1];
	for (j = 0; j <= (int)size - 1; j++)
	{
		if (array[j] >= p)
		{
			for (i = j; array[i] > p; i++)
			{
				continue;
			}
			swap = array[i];
			array[i] = array[j];
			array[j] = swap;
			print_array(array, size);
			if (i == (int)size - 1)
				break;
		}
	}
}
