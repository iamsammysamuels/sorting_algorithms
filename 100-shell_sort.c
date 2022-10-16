#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in
 * ascending order using the Shell sort algorithm, using the Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	int insert;
	size_t i, j, gap = 0;

	if (!array || size == 0)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			insert = array[i];
			j = i;
			while (j >= gap && array[j - gap] >= insert)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			if (array[j] != insert)
				array[j] = insert;
			i++;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

