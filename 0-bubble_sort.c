#include "sort.h"

/**
 * bubble_sort - bubble sort
 * description: sort an array of integers in ascending order
 * @array: array passed to us
 * @size: size of the array
 * Return: ordered array
 */

void bubble_sort(int *array, size_t size)
{
	size_t len;
	unsigned int i;
	int tmp;
	int check = 1;

	len = size;
	while (check && size > 1)
	{
		check = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				print_array(array, size);
				check = 1;
			}
		}
		len = len - 1;
	}
}
