#include "main.h"

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0 on successful execution.
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	char **av;
	int compt = 0;
	int exit_code = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		fflush(stdout);
		characters = getline(&buffer, &bufsize, stdin);

		if (characters == -1)
		{
			break;
		}
		compt++;
		if (buffer[characters - 1] == '\n')
		{
			buffer[characters - 1] = '\0';
		}
		av = split_string(buffer);
		if (av == NULL || av[0] == NULL)
		{
			free(av);
			continue;
		}
		exit_code = execute_command(av, buffer, compt);
	}
	free(buffer);
	return (exit_code);
}
