#include "shell.h"

/**
 * check_delim - func verifies char matches
 * @c: character to verify
 * @str: delimiters string
 * Return: Success (1), failure (0)
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (c == str[index])
		{
			return (1);
		}
	}
	return (0);
}
