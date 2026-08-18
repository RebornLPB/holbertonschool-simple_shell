#include "main.h"

/**
 * handle_exit - exits the shell when the exit builtin is used.
 * @av: array of arguments passed to the command.
 * @buffer: buffer pointer for input.
 *
 * Return: 0 when the command is not exit, otherwise exits the program.
 */
int handle_exit(char **av, char *buffer)
{
	if (strcmp(av[0], "exit") == 0)
	{
		free(av);
		exit(0);
	}
	return (0);
}
