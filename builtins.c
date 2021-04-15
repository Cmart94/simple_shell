#include "holberton.h"

/**
 * builtin_compare - Compare if the input command is a built in
 * @str: string to compare
 *
 * Return: The match built in, otherwise NULL
 */

char *builtin_compare(char *str)
{
	char *aux[] = {"cd", "env", "exit", NULL};
	int i = 0, r;

	for (i = 0; aux[i] != NULL; i++)
	{
		r = _strcmp(str, aux[i]);
		if (r == 0)
			return (aux[i]);
	}
	return (NULL);
}
/**
 * builtin_execution - executing built in function
 * @builtmatch: built in word with command with the match
 * @argv: array with the arguments
 * @array_read: array with buffer from read
 * @array_words: array with buffer from getline
 * Return: execition of built in function
 */

void builtin_execution(char *builtmatch, char **argv,
		       char *array_read[], char array_words[] __attribute__((unused)))
{
	unsigned int i = 0, j;
	char *_env = "env", *_cd = "cd", *_exit = "exit";

	if (_strcmp(builtmatch, _env) == 0)
	{
		while (environ[i] != NULL)
		{
			for (j = 0; environ[i][j] != '\0'; j++)
				;
			write(STDOUT_FILENO, environ[i], j);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	if (_strcmp(builtmatch, _cd) == 0)
	{
		write(STDOUT_FILENO, "Voy a cambiar de path\n", 22);
	}
	if (_strcmp(builtmatch, _exit) == 0)
	{
		free(argv);
		free(array_read);
		if (isatty(STDIN_FILENO) == 1)
		{
			free(array_words);
		}
		exit(EXIT_SUCCESS);
	}
}
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

