#include "holberton.h"

/**
 * _strlen - compare two strings
 * @s1: string to be count
 * Return: if equals return 0, -1 if don't
 */
int _strlen(char *s1)
{
	unsigned int i;

	for (i = 0; s1[i] != '\0'; i++)
		;
	return (i);
}
