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

/**
 * _strcpy - func copies string from src to dest
 * @dest: destination address
 * @src: source address
 * Return: dest pointer (Success)
 */
char *_strcpy(char *dest, const char *src)
{
	char *pos = dest;

	while (*src)
	{
		*pos++ = *src++;
	}
	*pos = '\0';

	return (dest);
}

/**
 * _strlen - func computes lengh of string
 * @str: string input
 * Return: length of string
 */
ssize_t _strlen(const char *str)
{
	const char *pos = str;

	if (!str)
	{
		return (-1);
	}

	while (*pos)
	{
		++pos;
	}

	return (pos - str);
}

/**
 * _strcmp - func compares s1 and s2
 * @s1: string input
 * @s2: string input
 * Return: s1 = s2 (0), s1 < s2 (-1), s1 > s2 (1)
 */
int _strcmp(const char *s1, const char *s2)
{
	for (; *s1 && *s2; ++s1, ++s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
	}

	if (*s1)
	{
		return (1);
	}
	if (*s2)
	{
		return (-1);
	}

	return (0);
}
