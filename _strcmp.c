#include "holberton.h"

/**
 * _strcmp - compare two strings
 * @str1: string to be compare with str2
 * @str2: string to be compare with str1
 * Return: if equals return 0, -1 if don't
 */
int _strcmp(char *str1, char *str2)
{
	unsigned int i, j = 0, k;

	for (k = 0; str2[k] != '\0'; k++)

		for (i = 0; i < k; i++)
		{
			if (str1[i] != str2[i])
			{
				j++;
			}
		}
	if (j != 0)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}
