#include "holberton.h"

/**
 * builtin_execution - executing built in function
 * @builtmatch: built in word with command with the match
 * @argv: array with the arguments
 * @array_read: array with buffer from read
 * @array_words: array with buffer from getline
 * Return: execition of built in function
 */

void builtin_execution(char *builtmatch, char *argv[] __attribute__((unused)),
		       char *array_read[], char array_words[])
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
		free(array_words);
		exit(EXIT_SUCCESS);
	}
}
