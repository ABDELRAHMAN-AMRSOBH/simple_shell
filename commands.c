#include "shell.h"

/**
 * execute_my_commands - check if command is one I made
 * @list: list of commands and arguments
 * @env: environment variable
 * @exit_code: exit code
 * @line: free before exit
 * Return: 0 if it works 1 if it doesn't
*/

int execute_my_commands(char **list, char **env, int *exit_code, char *line)
{
	int index;

	if (_strcmp(list[0], "exit") == 0)
	{
		exit_code[0] = list[1] ? _atoi(list[1]) : exit_code[0];
		free_array(list);
		free(line);
		exit(exit_code[0]);
	}
	if (_strcmp(list[0], "env") == 0)
	{
		for (index = 0; env[index]; index++)
			fprintf(stdout, "%s\n", env[index]);
		return (1);
	}
	return (0);
}

/**
 * get_path - takes a command search for it
 * @command: command
 * Return: path
*/

char *get_path(char *command)
{
	char *path = getenv("PATH"), *path_copy, *path_value, *full_path;
	struct stat sb;

	if (stat(command, &sb) == 0)
		return (command);
	if (path)
	{
		path_copy = _strdup(path);
		path_value = _strtok(path_copy, ":");
		while (path_value)
		{
			full_path = malloc(_strlen(command) + _strlen(path_value) + 2);
			_strcpy(full_path, path_value);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			_strcat(full_path, "\0");
			if (stat(full_path, &sb) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
			path_value = _strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}

/**
 * execute_commands - takes a command ask for path if exist execute
 * @list: list of commands and arguments
 * @name: name of file
 * @lines: line of output
 * @environment: environment variable
 * Return: exit code 0 in case no error 127 in case of an error
*/

int execute_commands(char **list, int lines, char *name, char **environment)
{
	char *command = get_path(list[0]);
	pid_t pid;
	int status, exit_code = 0;

	if (command)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(command, list, environment);
			exit(127);
		}
		waitpid(pid, &status, 0);
		if (command != list[0])
			free(command);
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", name, lines, list[0]);
		exit_code = 127;
	}
	return (exit_code);
}
