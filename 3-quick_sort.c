#include "sort.h"

/**
 * quick_sort2 - quick sort algorithms
 * description: sorts an array of ints in ascending order using the Quick
 * sort algorithm - includes the Lomuto partition scheme
 * @o_array: array of unsorted ints to print as sorted
 * @o_size: of array to print as sorted
 * @array: array of unsorted ints
 * @size: of array
 * Return: void
 */

void quick_sort2(int *o_array, size_t o_size, int *array, size_t size)
{
	int j, i, swap, p;

	if (array == NULL)
		return;
	if (size > 2)
	{
		p = array[size - 1];
		for (j = 0; j <= (int)size - 1; j++)
		{
			if (array[j] >= p)
			{
				for (i = j; array[i] > p; i++)
					continue;
				if (j != (int)size - 1)
				{
					swap = array[i];
					array[i] = array[j];
					array[j] = swap;
					print_array(o_array, o_size);
				}
				if (i == (int)size - 1)
					break;
			}
		}
		if (j > 0)
			quick_sort2(o_array, o_size, array, (j));
		if (j < (int)size - 1)
			quick_sort2(o_array, o_size, (array + j + 1),
				    (size - (j + 1)));
	}
	else
	{
		if (array[size - 1] < array[0])
		{
			swap = array[0];
			array[0] = array[size - 1];
			array[size - 1] = swap;
			print_array(o_array, o_size);
		}
	}
}

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
	quick_sort2(array, size, array, size);
}
