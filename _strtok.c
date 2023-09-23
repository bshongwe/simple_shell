#include "shell.h"

/**
 * _strtok - function that extracts tokens of a string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *tokens;
	static char *new_token;
	unsigned int index;

	if (str != NULL)
		new_token = str;
	tokens = new_token;
	if (tokens == NULL)
		return (NULL);
	for (index = 0; tokens[index] != '\0'; index++)
	{
		if (check_delim(tokens[index], delim) == 0)
			break;
	}
	if (new_token[index] == '\0' || new_token[index] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	tokens = new_token + index;
	new_token = tokens;
	for (index = 0; new_token[index] != '\0'; index++)
	{
		if (check_delim(new_token[index], delim) == 1)
			break;
	}
	if (new_token[index] == '\0')
		new_token = NULL;
	else
	{
		new_token[index] = '\0';
		new_token = new_token + index + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokens);
}
