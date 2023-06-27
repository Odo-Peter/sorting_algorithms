#include "sort.h"
/**
 * swap_first - look for a lesser value of a node inside the list where
 * the current value is bigger, in order to swap positions
 * @list: list to sort from
 *
 * Return: the node with the swapped value
 */

listint_t *swap_first(listint_t **list)
{
	listint_t *cursor;
	listint_t *next;
	listint_t *prev;
	listint_t *next_n;

	for (cursor = *list; cursor->next != NULL; cursor = cursor->next)
	{
		if (cursor->n > cursor->next->n)
		{
			next = cursor->next;
			prev = cursor->prev;
			next_n = next->next;
			cursor->next = next_n;
			cursor->prev = next;
			if (prev)
				prev->next = next;
			next->prev = prev;
			next->next = cursor;
			if (next_n)
				next_n->prev = cursor;
			cursor = cursor->prev;
			if (cursor->prev == NULL)
				*list = cursor;
			print_list(*list);
			break;
		}
	}
	return (cursor);
}


/**
 * check_backward - A loop from current node to check swap values
 * for values lesser than the previous node's values
 * @elem: node where we did the swap
 * @list: list to sort
 * Return: 0 if in the swap_first the node transverse to the tail.
 * 1 if the node transversal to the tail was futile
 * 2 if there was more minor values
 */

int check_backward(listint_t **elem, listint_t **list)
{
	listint_t *cursor, *next, *prev, *p_p;
	int a;

	if ((*elem)->next == NULL)
		a = 0;
	else
		a = 1;
	for (cursor = *elem; cursor && cursor->prev; cursor = cursor->prev)
	{
		if (cursor->n < cursor->prev->n)
		{
			next = cursor->next;
			prev = cursor->prev;
			p_p = prev->prev;
			cursor->next = prev;
			cursor->prev = p_p;
			if (p_p)
				p_p->next = cursor;
			if (next)
				next->prev = prev;
			prev->next = next;
			prev->prev = cursor;
			cursor = cursor->next;
			if (cursor->prev->prev != NULL)
				print_list(*list);
			else
				a = 2;
		}
	}
	*elem = cursor;
	return (a);
}


/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: unsorted list of integers
 * Return: A void function
 * returns nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cursor;
	int contd = 1;

	if (list == NULL || *list == NULL)
		return;

	while (contd != 0)
	{
		contd = 0;
		cursor = swap_first(list);
		if (cursor->next != NULL)
			contd = 1;
		cont = check_backward(&cursor, list);
		if (cursor->prev == NULL)
		{
			*list = cursor;
			if (contd != 0 && contd != 1)
				print_list(*list);
		}
	}
}
