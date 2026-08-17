#include "main.h"

/**
 * split_string - split a string into tokens using whitespace delimiters
 * @str: input string to split
 *
 * Return: NULL-terminated array of token strings,
 * or NULL on allocation failure
 */
char **split_string(char *str)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (!tokens)
		return (NULL);

	token = strtok(str, " \t\n");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
