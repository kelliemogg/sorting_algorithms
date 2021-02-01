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
	listint_t *tmp, *mvr;
	int check = 1;

	if (list == NULL || *list == NULL)
		return;
	mvr = *list;
	while (check && mvr != NULL && mvr->next != NULL)
	{
		check = 0;
		if (mvr->next->next == NULL && mvr->prev == NULL && mvr->n > mvr->next->n)
		{
			tmp = mvr->next;
			swap_nodes(list, tmp);
			print_list(*list);
			return;
		}
		if (mvr->next->n >= mvr->n)
			mvr = mvr->next;
		else if (mvr->n > mvr->next->n)
		{
			tmp = mvr->next;
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
		s_head_p = l_head->prev;
		/* swap the inner nodes and reconnect left node */
		tmp->prev = s_head_p;
		l_head->next = NULL;
		s_head_p->next = tmp;
	}
	else if (l_head->prev == NULL && tmp->next != NULL)
	{
		tmp_n = tmp->next;
		/* swap the inner nodes and reconnect right node */
		tmp->prev = NULL;
		l_head->next = tmp_n;
		tmp_n->prev = l_head;
		*list = tmp;
	}
	else if (l_head->prev == NULL && tmp->next == NULL)
	{
		tmp->prev = NULL;
		l_head->next = NULL;
		*list = tmp;
	}
	tmp->next = l_head;
	l_head->prev = tmp;
	return (tmp);
}
