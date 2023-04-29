#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	temp = node1->prev;
	node1->prev->next = node2;
	node2->prev->next = node1;

	node1->next->prev = node2;
	node2->next->prev = node1;

	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;

	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;

	print_list(*node1);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cursor;

	if (!list || !(*list) || !(*list)->next)
		return;

	cursor = *list;
	while (cursor->next)
	{
		if (cursor->n > cursor->next->n)
			swap_nodes(cursor, cursor->next);
		else
			cursor = cursor->next;
	}
}
