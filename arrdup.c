#include "tokens.h"

/**
 * arrdup - func duplicates NULL-term array
 * @arr: array input
 * Return: arr duplicate (Success)
 */
char **arrdup(char **arr)
{
	char **dup = NULL;
	size_t len = 0;

	if (!arr)
	{
		return (NULL);
	}
	while (arr[len++])
		;
	dup = malloc(sizeof(*dup) * len);
	if (!dup)
	{
		return (NULL);
	}
	while (len--)
	{
		dup[len] = _strdup(arr[len]);
	}
	return (dup);
}
