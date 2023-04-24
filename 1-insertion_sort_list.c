#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr, *prev, *next;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next = curr->next;
		prev = curr->prev;

		while (curr->prev != NULL && curr->next < curr->prev->next)
		{
			prev = curr->prev;
			prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev;
			curr->prev = prev->prev;
			curr->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = curr;
			prev->prev = curr;

			if (curr->prev == NULL)
				*list = curr;

			print_list(*list);
		}
		curr = next;
	}
}
