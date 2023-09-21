#include "string.h"

/**
  * _strnchr - func gets index of first matching strnchr
  * @str: string input
  * @chr: character input
  * @n: max number of characters to check for match
  * Return: index match, or -1 if strnchr is not found
  */
ssize_t _strnchr(const char *str, char chr, size_t n)
{
	ssize_t index;

	if (!str)
		return (-1);

	for (index = 0; n && str[index]; --n, ++index)
	{
		if (str[index] == chr)
			return (index);
	}

	return (-1);
}

/**
 * _strndup - func duplicates str
 * @str: string input
 * @n: max num bytes to copy
 * Return: if str is NULL or if memory allocation fails, return NULL,
 * otherwise return dynamically-allocated duplicate pointer
 */
char *_strndup(const char *str, size_t n)
{
	char *dup;
	size_t len = 0;

	if (!str)
		return (NULL);

	while (n && str[len])
		--n, ++len;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	dup[len] = '\0';

	while (len--)
		dup[len] = str[len];

	return (dup);
}

/**
 * _strnlen - func calculates str len
 * @str: string input
 * @n: max num chars to check
 * Return: lesser n and str len
 */
ssize_t _strnlen(const char *str, size_t n)
{
	const char *pos = str;

	if (!str)
		return (-1);

	while (n && *pos)
		--n, ++pos;

	return (pos - str);
}

/**
 * _strncmp - func compares s1 and s2
 * @s1: string input 1
 * @s2: stirng input 2
 * @n: max num bytes to compare
 * Return: 0 if s1 matches s2, or an integer less than 0 if s1 is less than s2,
 * otherwise an integer greater than 0 if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}

	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}

	return (0);
}

/**
 * _strncpy - func copies string to dest
 * @dest: destination
 * @src: source
 * @n: max num bytes to copy
 * Return: a pointer to dest
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *pos = dest;

	for ( ; n && *src; --n)
		*pos++ = *src++;
	if (n)
		*pos = '\0';

	return (dest);
}
