#include "sort.h"

/**
 * switch_fwd_bck - function swaps two nodes of a doubly linked list
 * @node: ...to swap
 * @list: pointer to doubly linked list
 */
void switch_fwd_bck(listint_t **node, listint_t **list)
{
	listint_t *temp = *node, *count1, *count2;

	if (!(*node)->prev)
		*list = (*node)->next;

	temp = count2 = *node;
	count1 = temp->next;

	temp->next = count1->next;
	count2 = temp->prev;
	temp->prev = count1;
	count1->next = temp;
	count1->prev = count2;

	if (count1->prev)
		count1->prev->next = count1;

	if (temp->next)
		temp->next->prev = temp;

	*node = count1;

}
/**
 * cocktail_sort_list - uses bidirectional bubble sort on doubly linked list
 * @list: pointer
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail;
	int cktail = 0, shaker = -1, sorts = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (sorts >= shaker)
	{
		shaker++;
		while (head->next && cktail != sorts)
		{
			if (head->n > head->next->n)
			{
				tail = head;
			       switch_fwd_bck(&tail, list);
			       print_list(*list);
			       head = tail;
			}

			cktail++;
			head = head->next;
		}

		if (shaker == 0)
			sorts = cktail;
		sorts--;
		while (head->prev && cktail >= shaker)
		{
			if (head->n < head->prev->n)
			{
				tail = head->prev;
				switch_fwd_bck(&tail, list);
				print_list(*list);
				head = tail->next;
			}
			cktail--;
			head = head->prev;
		}
	}
}
