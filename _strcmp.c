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
