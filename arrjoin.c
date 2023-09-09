#include "tokens.h"

/**
 * arrjoin - func joins arr1 and arr2 and prints a dynam-alloc array
 * @arr1: input array
 * @arr2: input array
 * Return: dynam-alloc array of arr1 and arr2 elements
 */
char **arrjoin(char **arr1, char **arr2)
{
	char ** new;
	size_t arr1_len = 0, arr2_len = 0, new_len;

	if (arr1)
	{
		while (arr1[arr1_len])
			++arr1_len;
	}
	if (arr2)
	{
		while (arr2[arr2_len])
			++arr2_len;
	}
	new = malloc(sizeof(char *) * (arr1_len + arr2_len + 1));
	if (!new)
	{
		return (NULL);
	}

	new_len = 0;
	if (arr1)
	{
		while (*arr1)
			new[new_len++] = _strdup(*arr1++);
	}
	if (arr2)
	{
		while (*arr2)
			new[new_len++] = _strdup(*arr2++);
	}
	new[new_len] = NULL;
	return (new);
}
