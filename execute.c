#include "main.h"

/**
 * execute_command - Fork a child process and execute the command in av.
 * Description: Creates a child process, executes the command in av[0],
 * and waits for the child process to finish before freeing allocated data.
 * @av: Array of arguments for the command to execute.
 * @buffer: Input buffer that is freed when execution finishes.
 */
int execute_command(char **av, char *buffer, int compt)
{
	pid_t child;
	int status;
	char *commandpath;

	commandpath = _wich(av[0]);
	if (commandpath == NULL)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", compt, av[0]);
		free(av);
		return(127);
	}

	child = fork();
		if (child == -1)
		{
			perror("Fork failed");
			free(commandpath);
			free(av);
			free(buffer);
			exit(1);
		}
		if (child == 0)
		{
			if (execve(commandpath, av, environ) == -1)
			{
				perror("./shell");
				free(commandpath);
				free(av);
				free(buffer);
				exit(1);
			}
			return (0);
		}
		else
		{
			wait(&status);
			free(commandpath);
			free(av);
			return (0);
		}
}
