#include "shell.h"

/**
 * main - run simple shell
 * @env: environment variable
 * @ac: count of arguments
 * @av: arguments
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	FILE *fp = stdin;
	size_t length = 0;
	int n_bytes = 0;
	char *line = 0, **list;
	int fd = isatty(STDIN_FILENO), lines = 0, exit_code = 0;

	if (ac > 1)
	{
		fp = fopen(av[1], "r");
		if (ac > 1 && !fp)
		{
			fprintf(stderr, "%s: 0: Can't open %s\n", av[0], av[1]);
			exit(127);
		}
	}
	while (n_bytes != -1)
	{
		lines++;
		if (ac == 1 && fd)
			fprintf(stdout, "$ ");
		n_bytes = getline(&line, &length, fp);
		if (n_bytes == -1)
		{
			if (ac == 1 && fd)
			fprintf(stdout, "\n");
			break;
		}
		line[n_bytes - 1] = 0;
		list = create_array(line);
		if (list)
		{
			if (!execute_my_commands(list, env, &exit_code, line))
				exit_code = execute_commands(list, lines, av[0], env);
			free_array(list);
		}
	}
	if (fp)
		fclose(fp);
	free(line);
	exit(exit_code);
}
