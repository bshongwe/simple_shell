#include "tokens.h"

/**
 * arrdup - func duplicates a \0 term array
 * @arr: array
 * Return: duplicate arr
 */
char **arrdup(char **arr)
{
	char **dup = NULL;
	size_t len = 0;

	if (!arr)
		return (NULL);
	while (arr[len++])
		;
	dup = malloc(sizeof(*dup) * len);
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = _strdup(arr[len]);
	return (dup);
}