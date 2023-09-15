#include "string.h"

/**
  * _strchr - func gets index of first matching char
  * @str: string input
  * @chr: character input
  * Return: matching index char
  */
ssize_t _strchr(const char *str, char chr)
{
	ssize_t index;

	if (!str)
	{
		return (-1);
	}

	for (index = 0; str[index]; ++index)
	{
		if (str[index] == chr)
			return (index);
	}

	return (-1);
}

/**
 * _strdup - func creates string copy in new array
 * @str: string to copy pointer
 * Return: If str is NULL or if memory allocation fails, return NULL,
 * otherwise return new copy pointer
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t size = 0;

	if (!str)
	{
		return (NULL);
	}

	while (str[size++])
		;

	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);

	while (size--)
	{
		dup[size] = str[size];
	}

	return (dup);
}

/**
 * _strlen - func calculates string len
 * @str: string input
 * Return: string len
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
 * _strcmp - func compares s1 annd s2
 * @s1: string input 1
 * @s2: string input 2
 * Return: 0 if s1 matches s2, otherwise an int
 * less than 0 if s1 is less than s2, otherwise an int
 * greater than 0 if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	for (; *s1 && *s2; ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
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

/**
 * _strcpy - func copies string to dest
 * @dest: destination
 * @src: source
 * Return: dest pointer
 */
char *_strcpy(char *dest, const char *src)
{
	char *pos = dest;

	while (*src)
		*pos++ = *src++;
	*pos = '\0';

	return (dest);
}
