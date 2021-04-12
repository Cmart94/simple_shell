#include "holberton.h"

/**
 * builtin_execution - executing built in function
 * @builtmatch: built in word with command with the match
 * @argv: array with the arguments
 * Return: execition of built in function
 */

void builtin_execution(char *builtmatch, char *argv[])
{
	unsigned int i = 0, j;
	char *_env = "env", *_cd = "cd", *_exit = "exit";

	printf("bliotmatch inside built execution: %s\n", builtmatch);
	printf("argv inside built execution: %s\n", argv[0]);
	if (_strcmp(builtmatch, _env) == 0)
	{
		printf("Voy a imprimir path global\n");
		while(environ[i] != NULL)
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
		printf("Voy a cambiar de path\n");
	}
	if (_strcmp(builtmatch, _exit) == 0)
	{
		printf("Voy a salirme\n");
		exit(EXIT_SUCCESS);
	}
	/*return (1);*/
}
