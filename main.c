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
		av = split_string(buffer);
		if (av == NULL || av[0] == NULL)
		{
			free(av);
			continue;
		}
		execute_command(av, buffer);
	}
	free(buffer);
	return (0);
}