#include "shell.h"

/**
 * word_length - return size of first word in string
 * @string: string of words
 * Return: word length
*/

int word_length(char *string)
{
	int length = 0;

	if (string)
		while (string[length] != ' ' && string[length] != '\0')
			length++;
	return (length);
}

/**
 * _strlen - return length of string
 * @string: string
 * Return: length of string
*/

int _strlen(const char *string)
{
	int length = 0;

	if (string)
		while (string[length] != '\0')
			length++;
	return (length);
}

/**
 * count_words - count words in string
 * @string: string of words
 * Return: number of words
*/

int count_words(char *string)
{
	int words = 0, index = 0;

	if (string)
		while (string[index])
		{
			if (string[index] != ' ')
			{
				words++;
				next_space(string, &index);
			}
			else
				next_word(string, &index);
		}
	return (words);
}
