#include "main.h"

/**
 * handle_exit - exits the shell when the exit builtin is used.
 * @av: array of arguments passed to the command.
 * @buffer: buffer pointer for input.
 * @exit_code: exit status to use when terminating the shell.
 *
 * Return: 0 when the command is not exit, otherwise exits the program.
 */
int handle_exit(char **av, char *buffer, int exit_code)
{
	if (strcmp(av[0], "exit") == 0)
	{
		free_all(av, buffer, NULL);
		exit(exit_code);
	}
	return (0);
}
