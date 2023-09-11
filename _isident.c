#include "ctype.h"

/**
 * _isident - func verifies if char is valid identifier char
 * @c: input char
 * Return: c is valid (1), c is invalid (0)
 */
bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}
