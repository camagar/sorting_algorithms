#include "sort.h"

/**
 * insertion_sort_list - function to order whyt the method insertion
 *@list: value
 * print_list - function to be printed
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *list_cop;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	list_cop = (*list)->next;

	while (list_cop)
	{
		while (list_cop->prev != NULL && list_cop->n < list_cop->prev->n)
		{
			list_cop->prev->next = list_cop->next;
			if (list_cop->next != NULL)
				list_cop->next->prev = list_cop->prev;
			list_cop->next = list_cop->prev;
			list_cop->prev = list_cop->prev->prev;
			list_cop->next->prev = list_cop;
			if (list_cop->prev == NULL)
				(*list) = list_cop;
			else
			{
				list_cop->prev->next = list_cop;
			}
			print_list(*list);
		}
		list_cop = list_cop->next;
	}
}
