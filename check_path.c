#include "holberton.h"

/**
 * check_path - check if the string has a '/'
 * @array: Pointer to first element of the array_words
 *
 * Return: if the string has an '/' return 0.
 */

int check_path(char *array)
{
	unsigned int i;

	for (i = 0; array[i] != '\0'; i++)
	{
		if (array[i] == '/')
		{
			return (0);
		}
	}
	return (-1);
}
