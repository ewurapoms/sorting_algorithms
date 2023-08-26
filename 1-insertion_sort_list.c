#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts ints in ascending order
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp;

	if (!list)
		return;

	node = *list;

	while (node)
	{
		while (node->next && (node->n > node->next->n))
		{
			tmp = node->next;
			node->next = tmp->next;
			tmp->prev = node->prev;

			if (node->prev)
				node->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = node;

			node->prev = tmp;
			tmp->next = node;

			if (tmp->prev)
				node = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
		node = node->next;
	}
}
