#include "holberton.h"
/**
 * function_execution - Execution of the process
 * @array_master: string to be evaluated
 * Return: On succes execution, otherwise print error
 */
void function_execution(char array_master[])
{
	char **array_words = NULL, *identificator = NULL, *built_compare = NULL;
	char *_path = NULL, *token = NULL, *ptr_conc = NULL;
	list_t *header = NULL;

	identificator = " ";
	array_words = buff_separator(array_master, identificator);
	built_compare = builtin_compare(array_words[0]);
	if (check_path(array_words[0]) == 0)
	{
		fork_execution(array_words);
	}
	else if (built_compare != NULL)
	{
		printf("built_compare: %s\n", built_compare);
		builtin_execution(built_compare, array_words);
	}
	else
	{
		printf("Vamos a concatenar PATH\n");
		_path = get_path();
		printf("_pah: %s\n", _path);
		token = strtok(_path, ":");
		while (token != NULL)
		{
			add_node_end(&header, token);
			printf("token del path: %s\n", token);
			token = strtok(NULL, ":");
		}
		ptr_conc = conc_check_list(&header, array_words[0]);
		printf("Valor prot_conc: %s\n", ptr_conc);
	}
}
