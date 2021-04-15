#include "holberton.h"

/**
 * _strcmp - compare two strings
 * @s1: string to be compare with str2
 * @s2: string to be compare with str1
 * Return: if equals return 0, -1 if don't
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 == s2)
		return (0);
	else
		return (*s1 - *s2);
}

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
/**
 * _strncmp - compare two strings
 * @s1: string to be compare with str2
 * @s2: string to be compare with str1
 * @size: size of s2
 * Return: if equals return 0, -1 if don't
 */
int _strncmp(char *s1, char *s2, size_t size)
{
	unsigned int i, count = 0;

	for (i = 0; i < size; i++)
	{
		if (s1[i] != s2[i])
		{
			count++;
		}
	}
	if (count != 0)
		return (-1);
	else
		return (0);
}
/**
 * _strcpy - function that concatenates two strings
 * @src: string source
 * Description: none
 * Return: dest
 */
char *_strcpy(char *src)
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
