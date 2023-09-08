#include "string.h"

/**
 * num_to_str - func converts num to str
 * @n: num from buffer
 * Return: string pointer
 */
char *num_to_str(size_t n)
{
	char *buf;
	size_t tmp = n, len = 1;

	while (tmp /= 10)
	{
		len++;
	}
	buf = malloc(len + 1);
	if (!buf)
	{
		return (NULL);
	}
	_num_to_str(&buf, n);
	return (buf - len);
}

/**
 * _num_to_str - func converts num to str
 * @buf: string in buffer
 * @n: number from buffer
 * Return: void
 */
static void _num_to_str(char **buf, size_t n)
{
	if (n > 9)
	{
		_num_to_str(buf, n / 10);
	}
	**buf = '0' + n % 10;
	*buf += 1;
	**buf = '\0';
}
