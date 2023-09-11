#include "ctype.h"

/**
 * _isalpha - func verifies if char is alphabetic
 * @c: char input
 * Return: c is alphabetic (1), is not alphabetic (0)
 */
bool _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
