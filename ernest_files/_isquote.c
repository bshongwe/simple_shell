#include "ctype.h"

/**
 * _isquote - func verifies if char is a quote
 * @c: char input
 * Return: c is a quote (1), is not a quote (0)
 */
bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
