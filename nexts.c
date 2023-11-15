#include "shell.h"

/**
 * next_space - move index to after space
 * @string: string of words
 * @index: index in string
*/

void next_space(char *string, int *index)
{
	while (string[*index] != ' ' && string[*index] != '\0')
		*index = *index + 1;
}

/**
 * next_word - move index to after word
 * @string: string of words
 * @index: index in string
*/

void next_word(char *string, int *index)
{
	while (string[*index] == ' ' && string[*index] != '\0')
		*index = *index + 1;
}
