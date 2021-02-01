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
		if (mover->next == NULL)
			return;
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

listint_t *swap_nodes(listint_t **list, listint_t *tmp)
{
	listint_t *l_head, *s_head_p, *tmp_n;
	/* define the inner nodes */
	l_head = tmp->prev;
	if (l_head->prev != NULL && tmp->next != NULL)
	{
		/* define outter nodes */
		s_head_p = l_head->prev;
		tmp_n = tmp->next;
		/* swap the inner nodes and reconnect */
		tmp->next = l_head;
		tmp->prev = s_head_p;
		l_head->next = tmp_n;
		l_head->prev = tmp;
		tmp_n->prev = l_head;
		s_head_p->next = tmp;
	}
	else if (l_head->prev != NULL && tmp->next == NULL)
	{
		/* define outer left node */
		s_head_p = l_head->prev;
		/* swap the inner nodes and reconnect left node */
		tmp->next = l_head;
		tmp->prev = s_head_p;
		l_head->next = NULL;
		l_head->prev = tmp;
		s_head_p->next = tmp;
	}
	else if (l_head->prev == NULL)
	{
		/* define outer right node */
		tmp_n = tmp->next;
		/* swap the inner nodes and reconnect right node */
		tmp->prev = NULL;
		tmp->next = l_head;
		l_head->prev = tmp;
		l_head->next = tmp_n;
		tmp_n->prev = l_head;
		*list = tmp;
	}
	return (tmp);
}
