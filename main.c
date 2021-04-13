#include "holberton.h"

/**
 * main - Entry point to shell programm
 *
 * Return: direction of head
 */

int main(void)
{
	ssize_t characters_read, characters;
	char buff_read[1024], **array_read = NULL, *identificator = NULL, **array_words = NULL;
	char *buffer = NULL;
	/*list_t *header = NULL;*/
	size_t buffsize = 1024;
	unsigned int count_read = 0;

	signal(SIGINT, sigintHandler);
	if (isatty(STDIN_FILENO) == 1) /*Interactive mode*/
	{
		buffer = malloc(buffsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("ERROR: unable to alocate buffer");
			exit(EXIT_FAILURE);
		}
		while (characters != EOF)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
			characters = getline(&buffer, &buffsize, stdin); /*Liberar en caso de que falle*/
			printf("%lu characters antes de corregir, buffer[%s]\n", characters, buffer);
			buffer[characters - 1] = '\0';
			printf("%lu characters leídos, buffer[%s]\n", characters, buffer);
			if (check_buffer(buffer) == 0)
			{
				printf("Path valido\n");
				function_execution(buffer);
			}
			else
			{
			}
			free(array_words);
		}
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else /*No interactive mode*/
	{
		characters_read = read(STDIN_FILENO, buff_read, 1024);
		identificator = "\n";
		buff_read[characters_read] = '\0';
		printf("Hay mas de un comando\n");/*print read*/
		array_read = buff_separator(buff_read, identificator);
		while (array_read[count_read] != NULL)
		{
			function_execution(array_read[count_read]);
			count_read++;
		}
		free(array_read);
		exit(0);
	}
	return (0);
}
