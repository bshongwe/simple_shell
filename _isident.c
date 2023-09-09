#include "ctype.h"

/**
 * _isident - func verifies if char is a valid identifier char
 * @c: input char
 * Return: c is valid (1), c is invalid (0)
 */
bool _isident(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}

}
