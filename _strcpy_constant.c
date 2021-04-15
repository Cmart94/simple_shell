#include "holberton.h"

/**
 * _strcpy_constant - function that concatenates two strings
 * @src: string source
 * Description: none
 * Return: dest
 */
char *_strcpy_constant(const char *src)
{
	char *dest = NULL;
	unsigned int len;

	for (len = 0; src[len] != '\0'; len++)
		;
	dest = malloc(sizeof(char) * (len + 1));
	for (len = 0; src[len] != '\0'; len++)
		dest[len] = src[len];
	dest[len] = '\0';
	return (dest);
}
