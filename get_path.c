#include "holberton.h"

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
