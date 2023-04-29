#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 * @list: doubly linked list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    if (!node2->prev)
        *list = node2;

    print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *left, *right;

    if (!list || !(*list) || !(*list)->next)
        return;

    left = *list;
    right = left->next;

    while (swapped)
    {
        swapped = 0;
        while (right)
        {
            if (right->n < left->n)
            {
                swap_nodes(left, right, list);
                swapped = 1;
                right = left->next;
                continue;
            }
            left = left->next, right = right->next;
        }
        if (!swapped)
            break;
        swapped = 0;
        while (left)
        {
            if (left->n < right->n)
            {
                swap_nodes(left, right, list);
                swapped = 1;
                left = right->prev;
                continue;
            }
            right = right->prev, left = left->prev;
        }
        left = (*list), right = left->next;
    }
}

