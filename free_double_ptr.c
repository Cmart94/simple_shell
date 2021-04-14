#include "holberton.h"

/**
 * free_double_ptr - compare two strings
 * @array_master: double pointer to be free
 * Return: void function
 */
void free_double_ptr(char **array_master)
{
	unsigned int i;

	for (i = 0; array_master[i] != NULL; i++)
	{
		free(array_master[i]);
	}
	free(array_master[i]);
	free(array_master);
}
