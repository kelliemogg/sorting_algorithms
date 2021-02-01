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
	listint_t *tmp;
	listint_t *s_head;
	int check = 1;

	if (list == NULL || *list == NULL)
		return;

	s_head = *list;
        while (check && s_head != NULL && s_head->next != NULL)
	{
		check = 0;
		if (s_head->next->n > s_head->n)
		{
			s_head = s_head->next;
		}
		else if (s_head->n > s_head->next->n)
		{
			tmp = s_head->next;
			swap_nodes(tmp);
			print_list(*list);
			while (tmp->n < tmp->prev->n && tmp->prev != NULL)
			{
				swap_nodes(tmp);
				print_list(*list);
			}
		}
		check = 1;
	}
}

void swap_nodes(listint_t *tmp)
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
		tmp_n->prev = l_head;
		l_head->prev = tmp;
		tmp->prev = NULL;
		tmp->next = l_head;
		l_head->next = tmp_n;
		printf("[%d] is l_head\n", l_head->n);
                printf("[%d] is tmp_n\n", tmp_n->n);
                printf("[%d] is tmp\n", tmp->n);
		/* losing tmp node (13) here*/
	}
}
