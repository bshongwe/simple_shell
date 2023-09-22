#include "main.h"

/**
 * custom_strtok - A simple version of the strtok function.
 * @str: The string to be tokenized.
 * @delim: The delimiter.
 * Return: The string pointer to the token.
 */

char *custom_strtok(char *str, const char *delim)
{
	static char *next_token;
	const char *d;
	char *token_start;

	if (str != NULL)
	{
		next_token = str;
	}
	if (next_token == NULL || *next_token == '\0')
	{
		return (NULL);
	}
	token_start = next_token;

	while (*next_token != '\0')
	{
		bool is_delim = false;

		for (d = delim; *d != '\0'; ++d)
		{
			if (*next_token == *d)
			{
				is_delim = true;
				break;
			}
		}
		if (is_delim)
		{
			*next_token = '\0';
			++next_token;
			return (token_start);
		}
		++next_token;
	}
	return (token_start);
}
