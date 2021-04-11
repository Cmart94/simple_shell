#include "holberton.h"

/**
 * function_execution - Execution of the process
 * @array_master: string to be evaluated
 * Return: On succes execution, otherwise print error
 */
void function_execution(char array_master[])
{
	char **array_words = NULL, *identificator;
	int status;
	unsigned int i;
	pid_t fork_pid;
	struct stat st;

	printf("array_master inside funtcion: %s\n", array_master);
	identificator = " ";
	array_words = buff_separator(array_master, identificator);
	if (check_path(array_words[0]) == 0)
	{
		printf("array_words antes de fork: %s", array_words[0]);
		if (stat(array_words[0], &st) == 0)
		{
			printf("Comando se encuentra");
			fork_pid = fork();
			if (fork_pid = 0)
			{
				if (execve(array_words[0], array_words, NULL) == -1)
				{
					perror("Error execve: ");
					exit(EXIT_FAILURE);
				}
				exit(EXIT_SUCCESS);
				printf("Estamos en el hijo");
			}
			else if (fork_pid > 0)
			{
				wait(&status);
				printf("Estamos en el padre");
			}
			else
			{
				perror("Error fork: ");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			perror("Error PATH: ");
			exit(EXIT_FAILURE);
		}
		
	}
}
