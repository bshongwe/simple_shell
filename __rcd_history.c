#include "shell.h"

/**
 * history - func writes user inputs file
 * @input: user input
 * Return: Success (0), fail (-1)
 */
int history_user_file(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
	{
		return (-1);
	}
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
	{
		return (-1);
	}
	if (input)
	{
		while (input[len])
		{
			len++;
		}
		w = write(fd, input, len);
		if (w < 0)
		{
			return (-1);
		}
	}
	return (1);
}
