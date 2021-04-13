#include "holberton.h"

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

	for(i = 0; i < size; i++)
	{
		if (s1[i] != s2[i])
		{
			count++;
		}
	}
	if (count != 0)
		return(-1);
	else
		return(0);
}
