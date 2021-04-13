#include "holberton.h"

/**
 * conc_check_list - Concatenate separe PATH with first element of array_words
 * @head: Double pointer to first node of linked list_t
 * @aux1: pointer to first position of array_words
 * Return: pointer to the concate string before the stat evaluation
 */

char *conc_check_list(list_t **head, char *aux1)
{
	const list_t *tmp;
	char *ptr_conc;
	int len1, len2, i, j = 0;
	struct stat fileStat;

	tmp = *head;

	while (tmp != NULL)
	{
		len1 = strlen(tmp->str);
		len2 = strlen(aux1);

		ptr_conc = malloc((len1 + len2 + 2) * sizeof(char));
		for (i = 0; i < (len1); i++)
		{
			ptr_conc[i] = tmp->str[i];
		}
		ptr_conc[i] = '/';
		len1++;
		for (i = (len1); i < (len1 + len2); i++)
		{
			ptr_conc[i] = aux1[j];
			j++;
		}
		ptr_conc[i] = '\0';
		j = 0;
		if (stat(ptr_conc, &fileStat) < 0)
		{
			printf("%s NOT FOUND\n", ptr_conc);
			tmp = tmp->next;
		}
		else
		{
			printf("%s FOUND\n", ptr_conc);
			return (ptr_conc);
		}
	}
	printf("aux no se encuentra en el Path");
	ptr_conc = NULL;
	return (ptr_conc);
}