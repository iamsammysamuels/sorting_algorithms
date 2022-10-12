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
	rec_quick_sort(array, 0, size - 1);
}

void rec_quick_sort(int *array, int start, int end)
{
	int p_index;

	if (start >= end)
		return;
	p_index = partition(array, start, end);
	rec_quick_sort(array, start, p_index - 1);
	rec_quick_sort(array, p_index + 1, end);
}

int partition(int *array, int start, int end)
{
	int p_index, pivot;


