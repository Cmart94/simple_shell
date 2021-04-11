#include "holberton.h"

/**
 * main - Entry point to shell programm
 *
 * Return: direction of head
 */

int main(void)
{
	ssize_t characters_read;
	char buff_read[1024], **array_read = NULL, *identificator;
	unsigned int count_read = 0;

	if (isatty(STDIN_FILENO) == 1) /*Interactive mode*/
	{
	}
	else /*No interactive mode*/
	{
		characters_read = read(STDIN_FILENO, buff_read, 1024);
		identificator = "\n";
		buff_read[characters_read] = '\0';
		printf("Hay mas de un comando\n");/*print read*/
		array_read = buff_separator(buff_read, identificator);
		while (array_read[count_read] != NULL)
		{
			function_execution(array_read[count_read]);
			count_read++;
		}
		exit(0);
	}
	return (0);
}
