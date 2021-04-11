#include "holberton.h"

/**
 * buff_separator - separate the buffer string of getline
 * @str: Pointer to the bugger string
 * @identificator: identificator for strtok
 * Return: array of pointers with str separate
 */

char **buff_separator(char *str, char *identificator)
{
	char **array_words = NULL, *token = NULL, *ptr = NULL;
	unsigned int i, j;

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
		printf("%s\n", token);
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
