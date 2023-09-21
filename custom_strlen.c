#include "main.h"

/**
 * custom_strlen - A strlen function counts string length.
 * @str: The string to be counted.
 * Return: Length or amount of chararaters counted.
 */

size_t custom_strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		str++;
		length++;
	}
	return (length);
}
