#include "ctype.h"

/**
 * _isdigit - func verifies if char is a digit
 * @c: char input
 * Return: integer (Success)
 */
bool _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
