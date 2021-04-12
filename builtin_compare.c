#include "holberton.h"

/**
 * builtin_compare - Compare if the input command is a built in
 * @str: string to compare
 *
 * Return: The match built in, otherwise NULL
 */

char *builtin_compare(char *str)
{
	char *aux[] = {"cd", "env", "exit", NULL};
	int i = 0, r;

	for (i = 0; aux[i] != NULL; i++)
	{
		r = _strcmp(str, aux[i]);
		if (r == 0)
			return (aux[i]);
	}
	return (NULL);
}
