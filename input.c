#include "getline.h"

/**
 * _read_input - func reads one line at a time from input
 * @lineptr: line buffer read from memory
 * @fd: file descriptor to be read from
 * Return: final quote state (Success)
 */
quote_state_t _read_input(char **lineptr, int fd)
{
	char *line = *lineptr = _getline(fd);
	size_t index = 0;
	static quote_state_t state = QUOTE_NONE;

	if (line)
	{
		switch (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
		{
			case QUOTE_DOUBLE:
			case QUOTE_SINGLE:
				do {
					index += quote_state_len(line + index, state);
					if (line[index] == '\0')
						continue;
					if (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
						index += 1;
			case 0:
					state = quote_state(line[index]);
					if (state & (QUOTE_DOUBLE | QUOTE SINGLE | QUOTE ESCAPE))
						index += 1;
				} while (line[index]);
		}
	}
	return (state);
}

/**
 * read_input - func fetches input
 * @info: shell programme info
 * Return: size of line in buffer (Success)
 */
bool read_input(info_t *info)
{
	char *line = NULL, *temp = NULL;

	if (info->interactive)
	{
		write(STDERR_FILENO, "$ ", 2);
	}

	info->lineno += 1;
	while (_read_input(&info->line, info->fileno) &
			(QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
	{
		temp = line;
		line = strjoin(NULL, "", temp, info->line);
		free(temp);
		free(info->line);
		if (info->interactive)
			write(STDERR_FILENO, "> ", 2);
		info->lineno += 1;
	}
	if (line)
	{
		temp = info->line;
		info->line = strjoin(NULL, "", line, temp);
		free(temp);
		free(line);
	}
	return (info->line);
