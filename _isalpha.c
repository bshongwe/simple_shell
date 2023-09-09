#include "ctype.h"

/**
 * _isalpha - func verifies if char is alphabetic
 * @c: char input
 * Return: c is alphabetic (1), is not alphabetic (0)
 */
bool _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
