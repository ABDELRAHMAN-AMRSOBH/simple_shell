#include "shell.h"

/**
 * create_array - takes a string return each word in a list alone
 * @string: string
 * Return: address of list
*/

char **create_array(char *string)
{
	char **list;
	int size = count_words(string), list_index = 0, string_index = 0;

	list = malloc(sizeof(char *) * (size + 1));
	if (list == 0 || size == 0)
		return (list ? free_subarray(list, list_index) : 0);
	list[size] = 0;
	while (list_index < size)
	{
		list[list_index] = dup_word(string, &string_index);
		if (list[list_index] == 0)
			return (free_subarray(list, list_index));
		list_index++;
	}
	return (list);
}

/**
 * create_subarray - takes a list and return slice of that list in new address
 * @list: list
 * @start: start of desired list
 * @end: end of desired list
 * Return: address of list
*/

char **create_subarray(char **list, int start, int end)
{
	char **new_list;
	int size = end - start + 1, index = start;

	new_list = malloc(sizeof(char *) * (size + 1));
	if (new_list == 0 || size < 1)
		return (new_list ? free_subarray(new_list, index - start) : 0);
	new_list[size] = 0;
	while (index - start < size)
	{
		new_list[index - start] = _strdup(list[index]);
		if (new_list[index - start] == 0)
			return (free_subarray(new_list, index));
		index++;
	}
	return (new_list);
}

/**
 * _atoi - create number from string
 * @s: input string.
 * Return: integer.
*/

int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}
	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
