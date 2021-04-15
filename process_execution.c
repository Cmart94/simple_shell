#include "holberton.h"
/**
 * fork_execution - Execution in different process
 * @array_words: string to be evaluated
 * Return: On succes execution, otherwise print error
 */
void fork_execution(char **array_words)
{
	int status;
	pid_t fork_pid;
	struct stat st;

	if (stat(array_words[0], &st) == 0)
	{
		fork_pid = fork();
		if (fork_pid == 0)
		{
			if (execve(array_words[0], array_words, NULL) == -1)
			{
				perror("Execve error");
				/*free_double_ptr(array_words);*/
				exit(EXIT_FAILURE);
			}
		}
		if (fork_pid != 0)
		{
			wait(&status);
			free(array_words);
		}
	}
	else
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			perror(array_words[0]);
			free(array_words);
		}
		else
		{
			perror(array_words[0]);
			free(array_words);
			exit(127);
		}
	}
}

/**
 * function_execution - Execution of the process
 * @array_master: string to be evaluated
 * @array_read: double array to be free
 * @path: string with the system path
 * @array_read: array from no interactive mode
 * @argv: Argument vector
 * @counter: counter of executions
 * Return: On succes execution, otherwise print error
 */
void function_execution(char array_master[], char *path,
			char **array_read, char *argv, int counter)
{
	char **array_words = NULL, *identificator = " ", *built_compare = NULL;
	char  *token = NULL, *ptr_conc = NULL, *_pathcpy;
	list_t *header = NULL;

	array_words = buff_separator(array_master, identificator);
	built_compare = builtin_compare(array_words[0]);
	if (check_path(array_words[0]) == 0)
	{
		fork_execution(array_words);
	}
	else if (built_compare != NULL)
	{
		builtin_execution(built_compare, array_words, array_read, array_master);
		free(array_words);
	}
	else
	{
		_pathcpy = _strcpy(path);
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
			error_handler(array_words, argv, counter, array_master, array_read);
		}
	}
}

/**
 * error_handler - Print error
 * @array_words: array of getline buffer
 * @argv: executable name
 * @array_master: array with the input string
 * @counter: imputs lines
 * @array_read: array of read buffer
 * Return: outpur error
 */

void error_handler(char *array_words[], char *argv, int counter,
		   char *array_master, char *array_read[])
{
	free(array_words);
	if (isatty(STDIN_FILENO) == 1)
	{
		print_error(argv, counter, array_master);
	}
	else
	{
		counter++;
		print_error(argv, counter, array_master);
		counter--;
		if (array_read[counter + 1] == NULL)
		{
			free(array_read);
			exit(127);
		}
	}
}

/**
 * print_error - Print error
 * @argv: executable name
 * @array_master: array with the input string
 * @counter: imputs lines
 * Return: On succes execution, otherwise print error
 */

void print_error(char *argv, int counter, char *array_master)
{
	char *num;

	num = _itoa(counter);
	write(STDOUT_FILENO, argv, _strlen(argv));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, num, _strlen(num));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, array_master, _strlen(array_master));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
	free(num);
}

/**
 * _itoa - convert integer type in shtring
 * @num: number to be convert to string
 * Return: string converted
 */
char *_itoa(int num)
{
	int i, rem, len = 0, n;
	char *str;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	str = malloc((len + 1) * sizeof(char));
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	return (str);
}
