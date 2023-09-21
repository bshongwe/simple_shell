#include "ctype.h"

/**
 * _isdigit - func verifies if char is a digit
 * @c: char input
 * Return: integer (Success)
 */
bool _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
