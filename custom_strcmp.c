#include "main.h"

/**
 * custom_strcmp - Simple string compare function.
 * @s1: String one.
 * @s2: String two.
 * Return: 0 if strings are the same, or non zero number if different.
 */

int custom_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
