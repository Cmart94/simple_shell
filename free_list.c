#include "holberton.h"

/**
 * free_list - prints all the elements of a list_t list
 * @head: Pointer to first node
 *
 * Return: direction of head
 */
void free_list(list_t *head)
{
	list_t *sig;

	while (head != NULL)
	{
		sig = head->next;
		free(head->str);
		free(head);
		head = sig;
	}
}
