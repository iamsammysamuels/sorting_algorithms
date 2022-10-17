#include "sort.h"

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: A pointer to the head node of the linked list to be sorted
 * Return: Void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *check = NULL, *curr = NULL, *temp = NULL;
	bool swapped = true;

	curr = *list;
	temp = *list;

	do {
		swapped = false;
		curr = *list;
		while (curr->next)
		{
			check = curr->next;
			if (curr->n > check->n)
			{
				curr->next = check->next;
				check->prev = curr->prev;
				if (check->next)
					check->next->prev = curr;
				if (curr->prev)
					curr->prev->next = check;
				curr->prev = check;
				check->next = curr;
				print_list(temp);
				swapped = true;
			}
			else
				curr = curr->next;
		}

		if (!swapped)
			break;

		while (curr->prev)
		{
			check = curr->prev;
			if (curr->n < check->n)
			{
				check->next = curr->next;
				if (check->prev)
					check->prev->next = curr;
				if (curr->next)
					curr->next->prev = check;
				curr->prev = check->prev;
				check->prev = curr;
				curr->next = check;
				if (!curr->prev)
					temp = curr;
				print_list(temp);
			}
			else
				curr = curr->prev;
		}
	}  while (swapped);
	if (!temp->prev)
		*list = temp;
}
