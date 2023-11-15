#include "shell.h"

/**
 * dup_word - dup word
 * @string: string contains word
 * @string_index: index in string
 * Return: address of new memory where dup word exist
*/

char *dup_word(char *string, int *string_index)
{
	int size, word_index = 0;
	char *word;

	next_word(string, string_index);
	size = word_length(string);
	word = malloc(size + 1);
	if (!word)
		return (0);
	word[size] = '\0';
	while (string[*string_index] != ' ' && string[*string_index] != '\0')
	{
		word[word_index] = string[*string_index];
		word_index = word_index + 1;
		*string_index = *string_index + 1;
	}
	return (word);
}

/**
 * _strdup - dup string
 * @string: string
 * Return: address of new string
*/

char *_strdup(char *string)
{
	int size = _strlen(string);
	char *word = malloc(size + 1);

	if (!word)
		return (0);
	word[size] = '\0';
	while (size--)
		word[size] = string[size];
	return (word);
}
