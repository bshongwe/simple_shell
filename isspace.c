#include "ctype.h"

/**
 * _isspace - func verifies if char is whitespace
 * @c: input char
 * Return: c is whitespace (1), not whitespace (0)
 */
bool _isspace(int c)
{
	if (c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
