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
/**
 * get_path - get the PATH from enviroment variables
 *
 * Return: pointer to the PATH
 */


char *get_path(void)
{
	unsigned int i = 0;
	char *aux = NULL, *_path = "PATH=";

	while (environ[i] != NULL)
	{
		if (!_strncmp(environ[i], _path, 5))
		{
			aux = environ[i] + 5;
		}
		i++;
	}
	return (aux);
}
