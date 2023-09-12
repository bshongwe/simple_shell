#include "string.h"

/**
 * _memset - func fills specific mem with specific value
 * @dest: specific mem init pointer
 * @chr: source value in specific mem
 * @n: mem size to fill
 * Return: dest (Success)
 */
void *_memset(void *dest, unsigned char chr, size_t n)
{
	unsigned char *mem = dest;

	if (dest)
	{
		while (n--)
		{
			*mem++ = chr;
		}
	}
	return (dest);
}

/**
 * _memcpy - func copies src mem area to dest mem area
 * @dest: target area head pointer
 * @src: source area head pointer
 * @n: n bytes to copy
 * Return: dest pointer
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char *r_pos = src;
	unsigned char *w_pos = dest;

	if (dest && src)
	{
		while (n--)
		{
			*w_pos++ = *r_pos++;
		}
	}
	return (dest);
}

/**
 * _memchr - func fetches matching value index
 * @src: memory area init search
 * @chr: matched value
 * @n: search are size
 * Return: matching byte index (Success), otherwise return -1
 */
ssize_t _memchr(const void *src, unsigned char chr, size_t n)
{
	ssize_t i = 0;
	const unsigned char *mem = src;

	if (src)
	{
		while (n--)
		{
			if (mem[i] == chr)
			{
				return (i);
			}
			i += 1;
		}
	}
	return (-1);
}

/**
 * _memdup - func duplicates mem area
 * @src: init source area pointer
 * @n: n bytes to duplicate
 * Return: dup memory pointer (Success), fail (NULL)
 */
void *_memdup(const void *src, size_t n)
{
	const unsigned char *r_pos = src;
	unsigned char *w_pos = dup;
	void *dup = malloc(n);

	if (dup)
	{
		while (n--)
		{
			*w_pos++ = *r_pos++;
		}
	}
	return (dup);
}
