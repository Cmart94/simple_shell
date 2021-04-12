#include "holberton.h"

/**
 * check_buffer - checks if buffer has a valid character
 *
 * @buffer: string to be check
 * Return: if are valid character 0, -1 if don't
 */
int check_buffer(char *buffer)
{
	char *identificator = " ";
	char *identificator1 = "\0";
	char *identificador2 = "\n";

	if (buffer == NULL)
	{
		printf("Buffer nulo\n");
		return (-1);
	}
	else if(_strcmp(buffer, identificator) == 0)
	{
		printf("Buffer vacío\n");
		return (-1);
	}
	else if (_strcmp(buffer, identificator1) == 0)
	{
		printf("Buffer nulo\n");
		return (-1);
	}
	else if (_strcmp(buffer, identificador2) == 0)
	{
		printf("Presiono enter\n");
		return (-1);
	}
	else
	{
		printf("Buffer valido\n");
		return (0);
	}
}
