#include "holberton.h"

/**
 * main - Entry point to shell programm
 *
 * Return: direction of head
 */


int main(void)
{
	char *path = NULL;

	signal(SIGINT, sigintHandler); /*Ctr + c exit handler*/
	path = get_path(); /*Create variable with the path*/
	if (isatty(STDIN_FILENO) == 1) /*Interactive mode*/
	{
		interactive_mode(path);
	}
	else /*No interactive mode*/
	{
		no_interactive_mode(path);
	}
	return (0);
}

/**
 * interactive_mode - Function that execute the interactive mode.
 * @path: environmetal variable with the PATH
 * Return: void function
 */
void interactive_mode(char *path)
{
	ssize_t characters;
	char **array_words = NULL, *buffer = NULL;
	size_t buffsize = 1024;

	buffer = malloc(buffsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("ERROR: unable to alocate buffer");
		exit(EXIT_FAILURE);
	}
	while (characters != EOF)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		while ((characters = getline(&buffer, &buffsize, stdin)) != -1)
		{
			buffer[characters - 1] = '\0';
			/*Check is buffer is empty or not*/
			if (check_buffer(buffer) == 0)
			{
				/*separate the buffer, evaluate if it's a path or not and execute*/
				function_execution(buffer, path);
			}
			free(array_words);
		}
	}
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * no_interactive_mode - function that execute the no interactive mode.
 * @path: environmetal variable with the PATH
 * Return: void function
 */

void no_interactive_mode(char *path)
{
	ssize_t characters_read;
	char buff_read[1024], **array_read = NULL, *identificator = NULL;
	unsigned int count_read = 0;

	characters_read = read(STDIN_FILENO, buff_read, 1024);
	identificator = "\n";
	buff_read[characters_read] = '\0';
	/*Separate lines of input and store it in array of pointers*/
	array_read = buff_separator(buff_read, identificator);
	while (array_read[count_read] != NULL)
	{
		/*separate the buffer, evaluate if it's a path or not and execute*/
		function_execution(array_read[count_read], path);
		count_read++;
	}
	free(array_read);
	exit(0);
}
