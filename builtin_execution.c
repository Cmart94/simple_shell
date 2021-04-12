#include "holberton.h"

/**
 * builtin_execution - executing built in function
 * @builtmatch: built in word with command with the match
 * @argv: array with the arguments
 * Return: execition of built in function
 */

void builtin_execution(char *builtmatch, char *argv[])
{
	int i;

	if (builtmatch == "env")
	{
		printf("Voy a imprimir path global\n");
		/*env_function();*/
	}
	if (builtmatch == "cd")
	{
		printf("Voy a cambiar de path\n");
	}
	if (builtmatch == "exit")
	{
		printf("Voy a salirme\n");
		exit(EXIT_SUCCESS);
	}
	/*return (1);*/
}
