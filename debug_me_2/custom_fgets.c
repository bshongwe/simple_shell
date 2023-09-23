#include "main.h"

/**
 * custom_fgets - A simple fgets function.
 * @str: String that is to be retrieved.
 * @size: The size.
 * @stream: A file discriptor. In, out, err.
 * Return: The string pointer.
 */

char *custom_fgets(char *str, int size, FILE *stream)
{
	int i;
	int c;

	if (size <= 0 || str == NULL || stream == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size - 1; i++)
	{
		c = fgetc(stream);
		if (c == EOF)
		{
			break;
		}
		str[i] = (char)c;
		if (c == '\n')
		{
			break;
		}
	}
	if (i == 0 && c == EOF)
	{
		return (NULL);
	}
	str[i] = '\0';
	return (str);
}
