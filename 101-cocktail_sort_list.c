#include "sort.h"

/**
 * cocktail_sort_list -  Sorts a doubly linked list in asscending order using
 * the Cocktail Shaker sort algorithm. Prints for every swap.
 * @list: Double pointer to the head node the doubly linked list
 * Return: Void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *r_head, *l_tail;

	/*Check for NULL's*/
	if (list == NULL || *list == NULL)
		return;

	/*Set r_head & l_tail*/
	r_head = *list;
	l_tail = get_tail(list);

	/*Check if r_head & l_tail have met*/
	while (r_head != NULL && r_head->next != l_tail &&
	      l_tail->prev != r_head && r_head != l_tail)
	{
	/*Sort to the right, change l_tail*/
		l_tail = sort_right(r_head, l_tail);

	/*Sort to the left, change r_head*/
		r_head = sort_left(l_tail, r_head);
	}

	/*Swap last 2 if nessicary*/
	if (r_head->next == l_tail && r_head->n > l_tail->n)
	{
		temp = current->next;
		temp->prev = current->prev;
		current->next = current->next->next;
		temp->next = current;
		current->prev = temp;
		print_list(*list);
	}
}

/**
 * get_tail - Finds and returns the tail node of a doubly liinked list
 * @list: Double pointer to doubly linked list
 * Return: Pointer to tail node, NULL on fail.
 */

listint_t *get_tail(listint_t **list)
{
	listint_t *curent = *list;

	if (list == NULL || *list == NULL)
		return (NULL);

	while (curent->next != NULL)
		current = current->next;

	return (current);
}

/**
 * sort_right - Sorts a section of doubbly linked list swaping higher value
 * nodes to the "right" from head to tail, printing the whole list each time
 * nodes a swaped. Then returns the node before the tail.
 * @list: Full list to print.
 * @r_head: Head node of list section.
 * @l_tail: Tail node of list section.
 * Return: Pointer to node before section tail. NULL on fail.
 */

listint_t *sort_right(listint_t **list, listint_t *r_head, listint_t *l_tail)
{
	listint_t *current = r_head, *temp;

	if (list == NULL || *list == NULL || r_haed == NULL || l_tail == NULL)
		return (NULL);

	while (current != l_tail)
	{
		if (current->n > current->next->n)
		{
			temp = current->next;
			temp->prev = current->prev;
			current->next = current->next->next;
			temp->next = current;
			current->prev = temp;
			print_list(*list);
			if (temp == l_tail)
				return (temp);
		}
		else
			current = current->next;
	}
	return (l_tail->prev);

}

/**
 * sort_left - Sorts a section of doubbly linked list swaping lower value
 * nodes to the "left" from tail to head, printing the whole list each time
 * nodes a swaped. Then returns the node before the head.
 * @list: Full list to print.
 * @r_head: Head node of list section.
 * @l_tail: Tail node of list section.
 * Return: Pointer to node before section tail. NULL on fail.
 */

listint_t *sort_left(listint_t **list, listint_t *l_tail, listint_t *r_head)
{

	if (list == NULL || *list == NULL || l_tail == NULL || r_head == NULL)
		return (NULL);

	while (current != l_tail)
	{
		if (current->n < current->prev->n)
		{
			temp = current->prev;
			temp->next = current->next;
			current->prev = current->prev->prev;
			temp->prev = current;
			current->next = temp;
			print_list(*list);
			if (temp == r_head)
				return (temp);
		}
		else
			current = current->next;
	}
	return (r_head->next);

}
