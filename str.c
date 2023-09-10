#include "string.h"

/**
 * _strchr - Get the index of the first matching charater.
 * @str: String passed.
 * @chr: Character passed.
 * Return: Index.
 */

ssize_t _strchr(const char *str, char chr)
{
	ssize_t index;

	if (str == NULL)
	{
		return (-1);
	}

	for (index = 0; str[index]; ++index)
	{
		if (str[index] == chr)
		{
			return (index);
		}
	}

	return (-1);
}

/**
 * _strdup - Create a duplicate of a string in an allocted array.
 * @str: A pointer to the string duplicate.
 * Return: A pointer to the duplicated string.
 * Otherwise return NULL if memory alloc fails or if string is NULL.
 */

char *_strdup(const char *str)
{
	char *dup;
	size_t size = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[size] != '\0')
	{
		size++;
	}

	dup = malloc(sizeof(char) * size);
	if (dup == NULL)
	{
		return (NULL);
	}

	while (size--)
	{
		dup[size] = str[size];
	}
	return (dup);
}
