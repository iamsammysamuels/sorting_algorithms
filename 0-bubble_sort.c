#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of
 * integers in ascending order
 * @array:  The array to be sorted
 * @size: The size of the array
 *
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int temp = 0;
	bool swapped;
	
	if (array == NULL || size == 0)
		return;
	do {
		swapped = false;
		for (i = 0; i < size - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		j++;
	} while (swapped);
}
