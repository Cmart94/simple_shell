#include "holberton.h"

/**
 * main - Entry point to shell programm
 *
 * Return: direction of head
 */

void interactive_mode(char *path);
void no_interactive_mode(char *path);

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
		if ((characters = getline(&buffer, &buffsize, stdin)) != -1)
		{
			buffer[characters - 1] = '\0';
			if (check_buffer(buffer) == 0) /*Check is buffer is empty or not*/
			{
				function_execution(buffer, path); /*separate the buffer, evaluate if it's a path or not and execute*/
			}
			free(array_words);
		}
	}
	free(buffer);
	exit(EXIT_SUCCESS);
}

void no_interactive_mode(char *path)
{
	ssize_t characters_read;
	char buff_read[1024], **array_read = NULL, *identificator = NULL;
	unsigned int count_read = 0;
	
	characters_read = read(STDIN_FILENO, buff_read, 1024);
	identificator = "\n";
	buff_read[characters_read] = '\0';
	array_read = buff_separator(buff_read, identificator); /*Separate lines of input and store it in array of pointers*/
	while (array_read[count_read] != NULL)
	{
		function_execution(array_read[count_read], path); /*separate the buffer, evaluate if it's a path or not and execute*/
		count_read++;
	}
	free(array_read);
	exit(0);
}
