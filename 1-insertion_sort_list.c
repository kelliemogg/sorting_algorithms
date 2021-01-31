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
	printf("[%d] - first s_head\n", s_head->n);
	while (check && s_head != NULL && s_head->next != NULL)
	{
		check = 0;
		if (s_head->next->n > s_head->n)
		{
			s_head = s_head->next;
			printf("[%d] - slide right s_head\n", s_head->n);
		}
		else if (s_head->n > s_head->next->n)
		{
			tmp = s_head->next;
			printf("[%d] - tmp for swap\n", tmp->n);
			swap_nodes(tmp);
			print_list(*list);
			/*else if (tmp->n < s_head_p->n && s_head_p->prev == NULL)
				make function for switching last two nodes*/
		}
		if (s_head->next != NULL)
			check = 1;
		else
			return;
	}
}

void swap_nodes(listint_t *tmp)
{
	listint_t *s_head, *s_head_p, *tmp_n;

	/* define the inner and outer nodes */
	s_head = tmp->prev;
	printf("[%d] - s_head in swap nodes\n", s_head->n);

	while (s_head->prev != NULL && tmp->next != NULL)
	{
		s_head_p = s_head->prev;
		if (tmp->next != NULL)
			tmp_n = tmp->next;

		tmp->next = s_head;
		tmp->prev = s_head_p;
		s_head->next = tmp_n;
		s_head->prev = tmp;
		tmp_n->prev = s_head;
		s_head_p->next = tmp;
		printf("[%d] is tmp after swap\n", tmp->n);
		printf("[%d] is s_head after swap\n", s_head->n);
		printf("[%d] is s_head_p after swap\n", s_head_p->n);
		printf("[%d] is tmp_n after swap\n", tmp_n->n);

/*		if (tmp->n < s_head_p->n && s_head_p->prev != NULL)
		{
			tmp->prev = s_head;
			s_head->next = tmp;
			s_head->prev = s_head_p;
			tmp->next = tmp_n;
			swap_nodes(tmp);
		}
*/	}
}
