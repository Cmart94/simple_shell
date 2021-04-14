#include "holberton.h"
/**
 * function_execution - Execution of the process
 * @array_master: string to be evaluated
 * @array_read: double array to be free
 * @path: string with the system path
 * Return: On succes execution, otherwise print error
 */
void function_execution(char array_master[], char *path, char **array_read)
{
	char **array_words = NULL, *identificator = " ", *built_compare = NULL;
	char  *token = NULL, *ptr_conc = NULL, *_pathcpy = _strcpy(path);
	list_t *header = NULL;

	array_words = buff_separator(array_master, identificator);
	built_compare = builtin_compare(array_words[0]);
	if (check_path(array_words[0]) == 0)
		fork_execution(array_words);
	else if (built_compare != NULL)
	{
		builtin_execution(built_compare, array_words);
		free(array_words);
	}
	else
	{
		token = strtok(_pathcpy, ":");
		while (token != NULL)
		{
			add_node_end(&header, token);
			token = strtok(NULL, ":");
		}
		free(_pathcpy);
		ptr_conc = conc_check_list(&header, array_words[0]);
		free_list(header);
		if (ptr_conc != NULL)
		{
			array_words[0] = ptr_conc;
			fork_execution(array_words);
			free(ptr_conc);
		}
		else
		{
			write(STDOUT_FILENO, "ERROR\n", 6);
			free(array_words);
			free(array_master);
			if (array_read != NULL)
				free(array_read);
			exit(127);
		}
	}
}
