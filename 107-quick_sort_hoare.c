#include "sort.h"

/**
 * swap_elements - Swaps 2 elements of an array
 * @arry: Array with elements to swap.
 * @id_1: Id of array to swap.
 * @id_2: Id of array to swap.
 * Return: void
 */

void swap_elements(int *arry, int id_1, int id_2)
{
	int temp = arry[id_2];

	arry[id_2] = arry[id_1];
	arry[id_1] = temp;
}

/**
 * quick_sort_hoare_recurse - Sorts an array using the quicksort Hoare
 * partition scheme by handeling the recursive passing.
 * @origin: The origional array for printing between swaps.
 * @o_size: Size of the origional array for printing.
 * @array: Array partition to sort.
 * @size: Size of the array partition.
 * Return: void
 */

void quick_sort_hoare_recurse(int *origin, size_t o_size,
			      int *array, size_t size)
{
	size_t piv = size - 1, move = 0, temp;

	if (size < 2 || origin == NULL || array == NULL)
		return;
	else
	{
		while (move != piv)
		{
			if (move < piv && array[move] > array[piv])
			{
				swap_elements(array, move, piv);
				print_array(origin, o_size);
				temp = move;
				move = piv;
				piv = temp;
			}
			else if (move > piv && array[move] <= array[piv])
			{
				swap_elements(array, move, piv);
				print_array(origin, o_size);
				temp = move;
				move = piv;
				piv = temp;
			}
			if (move > piv)
				move--;
			else if (move < piv)
				move++;
		}
		if (piv != size - 1)
			quick_sort_hoare_recurse(origin, o_size,
						 (array + piv + 1),
						 (size - (piv + 1)));
		if (piv != 0)
			quick_sort_hoare_recurse(origin, o_size,
						 array, (piv));
	}
}

/**
 * quick_sort_hoare - Sorts an array using the quicksort Hoare partition scheme
 * @array: Array to sort.
 * @size: Size of the array.
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL)
		return;
	quick_sort_hoare_recurse(array, size, array, size);
}
