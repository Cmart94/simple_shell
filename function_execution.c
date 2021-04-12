#include "holberton.h"
/**
 * function_execution - Execution of the process
 * @array_master: string to be evaluated
 * Return: On succes execution, otherwise print error
 */
void function_execution(char array_master[])
{
	char **array_words = NULL, *identificator, *built_compare;

	identificator = " ";
	array_words = buff_separator(array_master, identificator);
	if (check_path(array_words[0]) == 0)
	{
		fork_execution(array_words);
	}
	built_compare = builtin_compare(array_words[0]);
	if (built_compare != NULL)
	{
		printf("built_compare: %s\n", built_compare);
		builtin_execution(built_compare, array_words);
	}
}
