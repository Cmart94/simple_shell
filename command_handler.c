#include "holberton.h"

/**
 * buff_separator - separate the buffer string of getline
 * @str: pointer to the bugger string
 * @identificator: identificator for strtok
 * Return: array of pointers with str separate
 */

char **buff_separator(char *str, char *identificator)
{
	char **array_words = NULL, *token = NULL, *ptr = NULL;
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	ptr = malloc((i + 1) * sizeof(char));
	for (i = 0; str[i] != '\0'; i++)
		ptr[i] = str[i];

	ptr[i] = '\0';
	token = strtok(ptr, identificator);
	i = 0;
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, identificator);
	}
	free(ptr);

	array_words = malloc((i + 1) * sizeof(char *));
	token = strtok(str, identificator);
	i = 0;
	while (token != NULL)
	{
		array_words[i] = token;
		i++;
		token = strtok(NULL, identificator);
	}
	array_words[i] = NULL;
	return (array_words);
}
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
