#include "shell.h"

/**
 * _strchr - func identifies char in str
 * @s: str to be searched
 * @c: char to be identified
 * Return: pointer to char
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
 * _strcat - function concatenates dest and src
 * @dest: first string
 * @src: second string
 * Return: dest and src
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strcpy - func copies string
 * @dest: destination
 * @src: source
 * Return: destination
 */
char *_strcpy(char *dest, char *src)
{
	int index = 0;

	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/**
 * _strncmp - func compares num chars from s1 and s2
 * @s1: first string input
 * @s2: second string input
 * @n: num characters to compare
 * Return: no match (1), otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	if (s1 == NULL)
	{
		return (-1);
	}

	for (index = 0; index < n && s2[index]; index++)
	{
		if (s1[index] != s2[index])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - func duplicates str
 * @str: string input
 * Return: duplicated string (Success), fail (Null)
 */
char *_strdup(char *str)
{
	size_t len, index;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (index = 0; index <= len; index++)
	{
		str2[index] = str[index];
	}
	return (str2);
}
