#include "sort.h"

/**
 * swap_nodes - The Swaps for two nodes
 * @node1: Pointer of node 1
 * @node2: Pointer of node 2
 * @list: the blbla
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp = (*node1)->prev;

	(*node1)->next = (*node2)->next;

	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;

	(*node1)->prev = *node2;
	(*node2)->next = *node1;
	(*node2)->prev = temp;

	if ((*node2)->prev != NULL)
		(*node2)->prev->next = *node2;
	else
		*list = *node2;
}

/**
 * insertion_sort_list - the Sorts a doubly linked list using Insertion Sort
 * @list: Pointer to head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *act = NULL, *key = NULL;

	if (!list || !(*list))
		return;

	for (act = *list; act != NULL; act = act->next)
	{
		while (act->next != NULL && act->n > act->next->n)
		{
			key = act->next;
			while (key->prev != NULL && key->n < key->prev->n)
			{
				swap_nodes(list, &key->prev, &key);
				print_list(*list);
			}
		}
	}
}
