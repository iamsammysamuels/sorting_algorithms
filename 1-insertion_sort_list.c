#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list
 * of integers in ascending order
 * @list: a pointer to the head node of the list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *init, *temp;

	if (!list || !*list)
		return;

	temp = *list;
	curr = temp->next;

	while (curr)
	{
		init = curr->prev;
		while (init && curr->n < init->n)
		{
			init->next = curr->next;
			if (curr->next)
				curr->next->prev = init;
			if (init->prev)
				init->prev->next = curr;
			curr->prev = init->prev;
			curr->next = init;
			init->prev = curr;
			init = curr->prev;
			if (curr->prev == NULL)
				*list = curr;
			print_list(*list);
		}
		curr = curr->next;
	}
}
