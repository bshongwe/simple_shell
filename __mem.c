#include "shell.h"

/**
 * _realloc - func reallocates memory block using malloc and free
 * @ptr: pointer
 * @old_size: previous pointer size
 * @new_size: new pointer size
 * Return: reallocated memory pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * free_all - func frees allocated memory
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - func copies memory bytes from src to dest
 * @dest: dest pointer
 * @src: src pointer
 * @n: size to be copied
 * Return: pointer to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		dest[index] = src[index];
	}
	return (dest);
}

/**
 * fill_an_array - func fills constant byte to array in memory
 * @a: void pointer
 * @el: int
 * @len: length for int
 * Return: void pointer
 */
void *fill_cbyte_arr(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int index = 0;

	while (index < len)
	{
		*p = el;
		p++;
		index++;
	}
	return (a);
}

/**
 * _calloc - func allocates memory for an array using malloc
 * @size: size
 * Return: void pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int index;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (index = 0; index < size; index++)
	{
		a[index] = '\0';
	}
	return (a);
}
