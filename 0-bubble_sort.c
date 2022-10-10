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
	size_t i, j;
	int temp = 0;
	bool swapped;

	if (array == NULL || size == 0)
		return;
	for (j = 0; j < size; j++)
	{
		swapped = false;
		for (i = 0; i < size - 1 - i; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				swapped = true;
				print_array(array, size);
			}
			if (swapped == true)
				break;
		}
	}
}
