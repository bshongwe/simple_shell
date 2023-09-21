#include "main.h"

/**
 * custom_atoi - An atoi function ASSCI to interger.
 * @str: The string of ASSCI numbers to change to an integer.
 * Return: The integer value.
 */

int custom_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
