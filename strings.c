#include "shell.h"

/**
 * remove_letter - replace charater with 0
 * @charater: charater
 * @list: list of chars to be removed
 * Return: 1 if it works 0 otherwise
*/

int remove_letter(char *charater, const char *list)
{
	int size = _strlen(list);

	while (size--)
	{
		if (charater[0] == list[size])
		{
			charater[0] = '\0';
			return (1);
		}
	}
	return (0);
}

/**
 * _strtok - return value between string and list
 * @string: string
 * @list: list
 * Return: address of first byte of value
*/

char *_strtok(char *string, const char *list)
{
	static char *ptr;
	static int index;
	int start = index;
	int old = 0, new = 0;

	if (string)
	{
		ptr = string;
		start = index = 0;
	}
	if (ptr[index] == '\0')
		return (0);
	while (ptr[index])
	{
		old = new;
		new = remove_letter(&ptr[index], list);
		if (old && !new)
			break;
		index++;
	}
	return (&ptr[start]);
}

/**
 * _strcat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
*/

char *_strcat(char *dest, char *src)
{
	int count = 0, count2 = 0;

	while (*(dest + count) != '\0')
	{
		count++;
	}
	while (count2 >= 0)
	{
		*(dest + count) = *(src + count2);
		if (*(src + count2) == '\0')
			break;
		count++;
		count2++;
	}
	return (dest);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		op = *(s1 + i) - *(s2 + i);
		i++;
	}
	return (op);
}
