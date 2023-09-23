#include "shell.h"

/**
 * _itoa - func convert int to char
 * @n: integer input
 * Return: char pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, index = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[index] = (n % 10) + '0';
		n /= 10;
		index++;
	}

	s[index] = (n % 10) + '0';
	arr_rev(s, len);
	s[index + 1] = '\0';

	return (s);
}

/**
 * _strcmp - func compares s1 and s2
 * @s1: first input string
 * @s2: second input string
 * Return: identical strings (0), otherwise return difference
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, index, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (index = 0; s1[index]; index++)
	{
		if (s1[index] != s2[index])
		{
			cmp = s1[index] - s2[index];
			break;
		}
		else
			continue;

	}
	return (cmp);
}

/**
 * arr_rev - func reverses an array
 * @arr: array input to reverse
 * @len: array length
 */
void arr_rev(char *arr, int len)
{
	int index;
	char tmp;

	for (index = 0; index < (len / 2); index++)
	{
		tmp = arr[index];
		arr[index] = arr[(len - 1) - index];
		arr[(len - 1) - index] = tmp;
	}
}

/**
 * intlen - func computes int length
 * @num: integer input
 * Return: int length
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * _isalpha - func verifies if c is an alphabet
 * @c: char input
 * Return: true (1), false (0)
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
