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
