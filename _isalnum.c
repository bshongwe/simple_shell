#include "ctype.h"

/**
 * _isalnum - func verifies char is alphanumeric
 * @c: char input
 * Return: is alphanumeric (1), is not alphanumeric (0)
 */
bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
