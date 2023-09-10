#include "ctype.h"

/**
 * _isspecial_double - func verifies if char is special inbetween double quotes
 * @c: input char
 * Return: char is special (1), is not special (0)
 */
int _isspecial_double(char c)
{
	if (c == '\\')
	{
		return (1);
	}
	else if (c == 't')
	{
		return (1);
	}
	else if (c == 'n')
	{
		return (1);
	}
	else if (c == '\"')
	{
		return (1);
	}
	else if (c == 'v')
	{
		return (1);
	}
	else if (c == 'r')
	{
		return (1);
	}
	else if (c == 'f')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
