#include "sort.h"

/**
 * insertion_sort_list - insert nodes
 * description: sorts nodes in a linked list by swapping one by one until
 * the smalled value is at the head of the list
 * @list: linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *mover;
	int check = 1;

	if (list == NULL || *list == NULL)
		return;
	mover = *list;
	while (check && mover != NULL && mover->next != NULL)
	{
		check = 0;
		if (mover->next->next == NULL && mover->prev == NULL && mover->n > mover->next->n)
		{
			tmp = mover->next;
			swap_nodes(list, tmp);
			print_list(*list);
			return;
		}
		if (mover->next->n > mover->n)
			mover = mover->next;
		else if (mover->n > mover->next->n)
		{
			tmp = mover->next;
			swap_nodes(list, tmp);
			print_list(*list);
			while (tmp->prev != NULL && tmp->n < tmp->prev->n)
			{
				if (tmp->prev->prev != NULL)
				{
					swap_nodes(list, tmp);
					print_list(*list);
				}
				else if (tmp->prev->prev == NULL)
				{
					swap_nodes(list, tmp);
					print_list(*list);
				}
			}
		}
		check = 1;
	}
}
/**
 * swap_nodes - swaps nodes
 * description: swaps smaller node to the left
 * @list: list
 * @tmp: node to be swapped
 * Return: new list
 */

listint_t *swap_nodes(listint_t **list, listint_t *tmp)
{
	listint_t *l_head, *s_head_p, *tmp_n;

	l_head = tmp->prev;
	if (l_head->prev != NULL && tmp->next != NULL)
	{
		/* define outter nodes */
		s_head_p = l_head->prev;
		tmp_n = tmp->next;
		/* swap the inner nodes and reconnect */
		tmp->prev = s_head_p;
		l_head->next = tmp_n;
		tmp_n->prev = l_head;
		s_head_p->next = tmp;
	}
	else if (l_head->prev != NULL && tmp->next == NULL)
	{
		/* define outer left node */
		s_head_p = l_head->prev;
		/* swap the inner nodes and reconnect left node */
		tmp->prev = s_head_p;
		l_head->next = NULL;
		s_head_p->next = tmp;
	}
	else if (l_head->prev == NULL && tmp->next != NULL)
	{
		/* define outer right node */
		tmp_n = tmp->next;
		/* swap the inner nodes and reconnect right node */
		tmp->prev = NULL;
		l_head->next = tmp_n;
		tmp_n->prev = l_head;
		*list = tmp;
	}
	else if (l_head->prev == NULL && tmp->next == NULL)
	{
		tmp->next = l_head;
		tmp->prev = NULL;
		l_head->prev = tmp;
		l_head->next = NULL;
		*list = tmp;
	}
	tmp->next = l_head;
	l_head->prev = tmp;
	return (tmp);
}
