#include "ctype.h"

/**
 * _isnumber - func verifies string for strictly digits
 * @s: input string pointer
 * Return: true or false (boolean)
 */
bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!_isdigit(*s++))
			{
				return (false);
			}
		}
		return (true);
	}
	return (false);
}
