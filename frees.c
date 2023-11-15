#include "shell.h"

/**
 * free_array - frees list
 * @list: list to be freed
 * Return: 0
*/

void *free_array(char **list)
{
	int index = 0;

	while (list[index])
		free(list[index++]);
	free(list);
	return (0);
}

/**
 * free_subarray - frees list
 * @list: list
 * @limit: end of list
 * Return: 0
*/

void *free_subarray(char **list, int limit)
{
	int index = 0;

	while (index < limit)
		free(list[index++]);
	free(list);
	return (0);
}
