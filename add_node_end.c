#include "holberton.h"

/**
 * *add_node_end - add nodes at the end of the linked list
 * @head: Pointer to first node
 * @str: pointer to first member of lists
 * Return: direction of head
 */

list_t *add_node_end(list_t **head, const char *str)
{

	int i;
	list_t *new;
	list_t *tmp;

	for (i = 0; str[i] != '\0'; i++)
	{
	}
	new = (list_t *)malloc(sizeof(list_t));
	if (new != NULL)
	{
		new->str = _strcpy_constant(str);
		new->next = NULL;

		if (*head == NULL)
		{
			*head = new;
		}
		else
		{
			tmp = *head;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
		}
	}
	else
	{
		return (NULL);
	}
	return (*head);
}
