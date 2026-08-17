#include "main.h"

/**
 * _wich - searches PATH for a command and returns its full path.
 * @command: command name to locate.
 *
 * Return: full path to the command if found, otherwise NULL.
 */
char *_wich(const char *command)
{
	struct stat st;
	char *path, *dir, *fullpath;

	if (!command)
		return (NULL);

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	dir = strtok(path, ":");
	while (dir)
	{
		fullpath = malloc(strlen(dir) + strlen(command) + 2);
		if (!fullpath)
		{
			free(path);
			return (NULL);
		}

		if (stat(fullpath, &st) == 0)
		{
			return (fullpath);
		}

		free(fullpath);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
