#include "holberton.h"

/**
 * check_buffer - checks if buffer has a valid character
 *
 * @buffer: string to be check
 * Return: if are valid character 0, -1 if don't
 */
int check_buffer(char *buffer)
{
	char *identificator1 = "\0";
	char *identificador2 = "\n";
	unsigned int i, count = 0;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] != ' ')
			count++;
	}
	if (count == 0)
	{
		return (-1);
	}

	if (buffer == NULL)
	{
		return (-1);
	}
	else if (_strcmp(buffer, identificator1) == 0)
	{
		return (-1);
	}
	else if (_strcmp(buffer, identificador2) == 0)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}
