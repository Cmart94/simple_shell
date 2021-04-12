#include "holberton.h"
/**
 * fork_execution - Execution in different process
 * @array_master: string to be evaluated
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
				perror("Error execve: ");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else if (fork_pid > 0)
			wait(&status);
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
