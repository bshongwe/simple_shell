#include "ctype.h"

/**
 * _isspecial_double - func verifies if char is special inbetween double quotes
 * @c: input char
 * Return: char is special (1), is not special (0)
 */
int _isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
