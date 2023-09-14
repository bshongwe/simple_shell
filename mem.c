#include "string.h"
#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>

/**
 * _memchr - func gets index of first matching value
 * @src: start of memory area to search
 * @chr: value to find
 * @n: size of search area
 * Return: If chr does not occur in the first n elements of src, return -1.
 * Otherwise, return the index of the first occurence of chr.
 */
ssize_t _memchr(const void *src, unsigned char chr, size_t n)
{
	const unsigned char *mem = src;
	ssize_t i = 0;

	if (src)
	{
		while (n--)
		{
			if (mem[i] == chr)
				return (i);
			i += 1;
		}
	}
	return (-1);
}

/**
 * _memcpy - func copies memory area
 * @dest: start of the target area pointer
 * @src: start of the source area pointer
 * @n: num bytes to copy 
 * Return: a pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *w_pos = dest;
	const unsigned char *r_pos = src;

	if (dest && src)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dest);
}

/**
 * _memdup - func duplicates memory area
 * @src: start of the source area pointer
 * @n: num bytes to duplicate
 * Return: If memory allocation fails, return NULL. Otherwise, return a
 * pointer to the start of the duplicated memory.
 */
void *_memdup(const void *src, size_t n)
{
	void *dup = malloc(n);
	unsigned char *w_pos = dup;
	const unsigned char *r_pos = src;

	if (dup)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dup);
}

/**
 * _memset - func fills region of memory with given value
 * @dest: beginning of region pointer
 * @chr: value to write to region
 * @n: num bytes to write
 * Return: dest
 */
void *_memset(void *dest, unsigned char chr, size_t n)
{
	unsigned char *mem = dest;

	if (dest)
	{
		while (n--)
			*mem++ = chr;
	}
	return (dest);
}