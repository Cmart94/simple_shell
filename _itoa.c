#include "holberton.h"

/**
 * _itoa - convert integer type in shtring
 * @num: number to be convert to string
 * Return: string converted
 */
char *_itoa(int num)
{
	int i, rem, len = 0, n;
	char *str;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	str = malloc((len + 1) * sizeof(char));
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	return (str);
}
