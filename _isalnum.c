#include "ctype.h"

/**
 * _isalnum - func verifies char is alphanumeric
 * @c: char input
 * Return: is alphanumeric (1), is not alphanumeric (0)
 */
bool _isalnum(int c)
{
	if ((c >= 0 && c <= 9) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
