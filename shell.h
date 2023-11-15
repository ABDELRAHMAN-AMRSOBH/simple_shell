#ifndef SHELL_H
#define SHELL_H

/* libraries */
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* frees.c - uses free and return 0 */
void *free_array(char **list);
void *free_subarray(char **list, int limit);

/* nexts.c - change index to space or not space */
void next_space(char *string, int *index);
void next_word(char *string, int *index);

/* sizes.c - count letters and words return count */
int word_length(char *string);
int _strlen(const char *string);
int count_words(char *string);

/* strings.c - return word or string or line */
int remove_letter(char *charater, const char *list);
char *_strtok(char *string, const char *list);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* duplicates.c - copys entire string or just word return copy */
char *dup_word(char *string, int *string_index);
char *_strdup(char *string);

/* creates.c - creates list of words from                */
/* string containing more than one word or bigger list   */

char **create_array(char *string);
char **create_subarray(char **list, int start, int end);
int _atoi(char *s);

/* commands.c - handles commands */

int execute_my_commands(char **list, char **env, int *exit_code, char *line);
int execute_commands(char **list, int lines, char *name, char **environment);
char *get_path(char *command);

#endif
