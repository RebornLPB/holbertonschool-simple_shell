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
	char *path, *temp, *dir, *fullpath;

	if (!command)
		return (NULL);
	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);

	temp = strdup(path);
	if (!temp)
		return (NULL);

	dir = strtok(temp, ":");
	while (dir)
	{
		fullpath = malloc(strlen(dir) + strlen(command) + 2);
		if (!fullpath)
		{
			free(temp);
			return (NULL);
		}
		sprintf(fullpath, "%s/%s", dir, command);
		if (stat(fullpath, &st) == 0)
		{
			free(temp);
			return (fullpath);
		}

		free(fullpath);
		dir = strtok(NULL, ":");
	}
	free(temp);
	return (NULL);
}
