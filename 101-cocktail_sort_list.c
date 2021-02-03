#include "sort.h"

/**
 * get_tail - Finds and returns the tail node of a doubly liinked list
 * @list: Double pointer to doubly linked list
 * Return: Pointer to tail node, NULL on fail.
 */

listint_t *get_tail(listint_t **list)
{
	listint_t *current = *list;

	if (list == NULL || *list == NULL)
		return (NULL);

	while (current->next != NULL)
		current = current->next;

	return (current);
}

/**
 * swap - Swaps the position of 2 nodes in a doubly linked list, then prints
 * the list. Must recieve the eariler "left" node and that
 * "right" is left->next.
 * @list: Double pointer to the head node of the list
 * @left: Node that comes first in the doubly linked list
 * Return: Void
 */

void swap(listint_t **list, listint_t *left)
{
	listint_t *p_left = NULL, *n_right = NULL, *right = left->next;

	if (list == NULL || *list == NULL || left == NULL)
		exit(0);

	/*if nodes existed on either side, change the nodes they point to*/
	if (left->prev != NULL)
	{
		p_left = left->prev;
		p_left->next = right;
	}

	if (right->next != NULL)
	{
		n_right = right->next;
		n_right->prev = left;
	}

	/*swap 2 inner nodes*/
	right->prev = left->prev;
	left->prev = right;
	left->next = right->next;
	right->next = left;

	/*Make sure to move the head if it was swaped*/
	if (*list == left)
		*list = right;

	print_list(*list);
}

/**
 * sort_right - Sorts a section of doubbly linked list swaping higher value
 * nodes to the "right" from head to tail, printing the whole list each time
 * nodes a swaped. Then returns the node before the tail.
 * @list: Full list to print.
 * @l_head: Head node of list section.
 * @r_tail: Tail node of list section.
 * Return: Pointer to node before section tail. NULL on fail or no swap.
 */

listint_t *sort_right(listint_t **list, listint_t **l_head, listint_t *r_tail)
{
	listint_t *current = *l_head;
	int swaped = 0;

	if (list == NULL || *list == NULL || *l_head == NULL || r_tail == NULL)
		return (NULL);

	while (current != r_tail)
	{
		if (current->n > current->next->n)
		{
			if (current == *l_head)
				*l_head = current->next;
			swaped = 1;
			swap(list, current);
			if (current->prev == r_tail)
				return (current);
		}
		else
			current = current->next;
	}
	if (swaped == 0)
		return (NULL);
	return (r_tail->prev);

}

/**
 * sort_left - Sorts a section of doubbly linked list swaping lower value
 * nodes to the "left" from tail to head, printing the whole list each time
 * nodes a swaped. Then returns the node before the head.
 * @list: Full list to print.
 * @l_head: Head node of list section.
 * @r_tail: Tail node of list section.
 * Return: Pointer to node before section tail. NULL on fail or no swap.
 */

listint_t *sort_left(listint_t **list, listint_t *r_tail, listint_t *l_head)
{
	listint_t *current = r_tail;
	int swaped = 0;

	if (list == NULL || *list == NULL || r_tail == NULL || l_head == NULL)
		return (NULL);

	while (current != l_head)
	{
		if (current->n < current->prev->n)
		{
			swaped = 1;
			swap(list, current->prev);
			if (current->next == l_head)
				return (l_head);
		}
		else
			current = current->prev;
	}
	if (swaped == 0)
		return (NULL);
	return (l_head->next);

}

/**
 * cocktail_sort_list -  Sorts a doubly linked list in asscending order using
 * the Cocktail Shaker sort algorithm. Prints for every swap.
 * @list: Double pointer to the head node the doubly linked list
 * Return: Void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *l_head, *r_tail, *current, *temp;

	/*Check for NULL's*/
	if (list == NULL || *list == NULL)
		return;

	/*Set l_head & r_tail*/
	l_head = *list;
	r_tail = get_tail(list);

	/*Check if l_head & r_tail have met*/
	while (l_head != NULL && l_head->next != r_tail &&
	       r_tail->prev != l_head && l_head != r_tail)
	{
		/*Sort to the right, change r_tail*/
		r_tail = sort_right(list, &l_head, r_tail);
		if (r_tail == NULL)
			return;
		/*Sort to the left, change l_head*/
		l_head = sort_left(list, r_tail, l_head);
		if (l_head == NULL)
			return;
	}

	/*Swap last 2 if nessicary*/
	if (l_head->next == r_tail && l_head->n > r_tail->n)
	{
		current = l_head;
		temp = current->next;
		temp->prev = current->prev;
		current->next = current->next->next;
		temp->next = current;
		current->prev = temp;
		/*Make sure to move the head if it was swaped*/
		if (*list == current)
			*list = temp;
		print_list(*list);
	}
}
