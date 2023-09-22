#include "main.h"

/**
 * custom_strcspn - A simple version of the strcspn function.
 * @str: The string.
 * @reject: The char to be rejected from the string.
 * Return: The legth of the string without the reject.
 */

size_t custom_strcspn(const char *str, const char *reject)
{
	size_t length = 0;

	while (*str != '\0')
	{
		const char *r = reject;

		while (*r != '\0')
		{
			if (*str == *r)
			{
				return (length);
			}
			r++;
		}
		str++;
		length++;
	}
	return (length);
}
