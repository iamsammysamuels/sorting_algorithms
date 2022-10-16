#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	rec_quick_sort(array, 0, size - 1, size);
}

/**
 * rec_quick_sort - Calls the prtition function as long as
 * the start is less than end
 * @array: The array to be partitioned
 * @start: The first index of the array
 * @end: The last index of the array
 * @size: The size of the array
 *
 * Return: void
 */
void rec_quick_sort(int *array, int start, int end, size_t size)
{
	int p_index;

	if (start >= end)
		return;
	p_index = partition(array, start, end, size);
	rec_quick_sort(array, start, p_index - 1, size);
	rec_quick_sort(array, p_index + 1, end, size);
}

/**
 * partition - Partitions an array of integers
 * @array: The array to be partitioned
 * @start: The first index of the array
 * @end: The last index of the array
 * @size: The size of the array
 *
 * Return: The paritition index of the partitioned array
 */
int partition(int *array, int start, int end, size_t size)
{
	int p_index, pivot, temp, i;

	p_index = start - 1;
	pivot = end;

	for (i = start; i < end; i++)
	{
		if (array[i] < array[pivot])
		{
			p_index++;
			if (array[i] != array[p_index])
			{
				temp = array[i];
				array[i] = array[p_index];
				array[p_index] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[p_index + 1] != array[pivot])
	{
		temp = array[pivot];
		array[pivot] = array[p_index + 1];
		array[p_index + 1] = temp;
		print_array(array, size);
	}
	return (p_index + 1);
}
