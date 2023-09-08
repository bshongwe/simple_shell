#include "builtins.h"
#include "string.h"

/**
 * atou - func converts string to int
 * @s: char int to verify and convert
 * Return: conveted int (Success)
 */
unsigned int atou(char *s)
{
	size_t a;
	unsigned int num = 0;
	unsigned int to_add;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (UINT_MAX / 10 < NUM)
		{
			return (UNIT_MAX);
		}

		num *= 10;
		to_add = s[a] - '0';
		if (UINT_MAX - to_add < num)
		{
			return (UINT_MAX);
		}
		num += to_add;
	}
	return (num);
}
