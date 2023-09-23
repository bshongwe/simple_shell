#include "shell.h"

/**
 * _putchar - func writes char to stdout
 * @c: char to print
 * Return: char to std output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - func prints str using _putchar function
 * @str: string pointer
 * Return: void
 */
void _puts(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		_putchar(str[index]);
	}
	_putchar('\n');
}

/**
 * _atoi - func converts chars in string to a integer
 * @s: string input
 * Return: converted integer
 */
int _atoi(char *s)
{
	int index = 0, b = 1, j;
	unsigned int l = 0;

	while (s[index] != '\0')
	{
		if (s[index] == '-')
		{
			return (2);
		}
		j = s[index] - '0';

		if (l > 0 && !(j >= 0 && j <= 9))
			break;

		if (j >= 0 && j <= 9)
			l = l * 10 + j;

		index++;
	}
	l *= b;
	return (l);
}

/**
 * _strncpy - func copies string
 * @dest: dest string
 * @src: src string
 * @n: num chars copied to memory
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int index = 0;

	while (index < n && *(src + index))
	{
		*(dest + index) = *(src + index);
		index++;
	}
	while (index < n)
	{
		*(dest + index) = '\0';
		index++;
	}
	return (dest);
}

/**
 * _strlen - func counts string length
 * @s: string input
 * Return: string length
 */
int _strlen(char *s)
{
	int index;

	for (index = 0; s[index] != '\0'; index++)
	{
		continue;
	}
	return (index);
}
