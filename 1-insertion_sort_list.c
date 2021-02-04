#include "sort.h"


/**
 * swap1 - sort and array
 * @tprev: node prev
 * @tnext: node next
 * Return: no return
 */
void swap1(listint_t *tprev, listint_t *tnext)
{
	if (tprev->prev)
		tprev->prev->next = tnext;
	if (tnext->next)
		tnext->next->prev = tprev;
	tprev->next = tnext->next;
	tnext->prev = tprev->prev;
	tprev->prev = tnext;
	tnext->next = tprev;
}

/**
 * swap2 - sort and array
 * @tnext: node prev
 * @tprev: node next
 * Return: no return
 */
void swap2(listint_t *tnext, listint_t *tprev)
{

	if (tnext->prev)
		tnext->prev->next = tprev;
	if (tprev->next)
		tprev->next->prev = tnext;
	tnext->next = tprev->next;
	tprev->prev = tnext->prev;
	tnext->prev = tprev;
	tprev->next = tnext;
}

/**
 * swap3 - sort and array
 * @tnext: node prev
 * @tprev: node next
 * @list: head liked list
 * Return: no return
 */
void swap3(listint_t **list, listint_t *tprev, listint_t *tnext)
{
	if (!tnext->next)
	{
		tprev->prev = tnext;
		tnext->next = tprev;
		tnext->prev = NULL;
		tprev->next = NULL;
		*list = tnext;
		print_list(*list);
	} else
	{
		tnext->next->prev = tprev;
		tprev->next = tnext->next;
		tprev->prev = tnext;
		tnext->next = tprev;
		tnext->prev = NULL;
		if (!tnext->prev)
			*list = tnext;
	}
}
