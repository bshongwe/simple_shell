#include "ctype.h"

/**
 * _isspecial_double - func verifies if char is special inbetween double quotes
 * @c: input char
 * Return: char is special (1), is not special (0)
 */
int _isspecial_double(char c)
{
	if (c == '\\')
	{
		/*\*/
		return (1);
	}
	else if (c == 't')
	{
		/*tab*/
		return (1);
	}
	else if (c == 'n')
	{
		/*newline*/
		return (1);
	}
	else if (c == '\"')
	{
		/*"*/
		return (1);
	}
	else if (c == 'v')
	{
		/*vertical tab: not sure if I coded for this*/
		return (1);
	}
	else if (c == 'r')
	{
		/*return AKA enter: this too*/
		return (1);
	}
	else if (c == 'f')
	{
		/*form feed, Never heard of this one before, but it is special: and this too*/
		return (1);
	}
	else
	{
		/*not special: let's hope this will work*/
		return (0);
	}
}
