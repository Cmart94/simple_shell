#include "holberton.h"

/**
 * count_commands - count number of commands froms read
 * @str_read: Pointer to string
 *
 * Return: Integer
 */

int count_commands(char *str_read)
{
	unsigned int i, count = 0;

	for (i = 0; str_read[i] != '\0'; i++)
	{
		if (str_read[i] == '\n')
		{
			count++;
		}
	}
	return (count);
}
