#include "getline.h"
#include "hsh.h"

/**
 * read_input - func gets input
 * @info: shell information
 * Return: line size
 */
bool read_input(info_t *info)
{
	char *line = NULL, *temp = NULL;

	if (info->interactive)
		write(STDERR_FILENO, "$ ", 2);

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
}

/**
 * _read_input - func reads single line
 * @lineptr: line buffer
 * @fd: file descriptor to read from
 * Return: ending quote state
 */
quote_state_t _read_input(char **lineptr, int fd)
{
	char *line = *lineptr = _getline(fd);
	static quote_state_t state = QUOTE_NONE;
	size_t index = 0;
	int argc;

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
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
					index += 1;
					argc = 5;
					/*fallthrough;*/
		case 1:
			break;
			} while (line[index]);
		}
	}
	return (state);
}

/**
 * read_argc_and_value - func reads argc and value stored in index
 * @param line: line to read from
 * @param index: index of value to read
 * Return: value stored in the index, or NULL if the index is out of range
 */
char *read_argc_and_value(char *line, size_t index)
{
	char **argv = strsplit(line, ' ');
	int argc = read_argc_and_value(line, 2);
	char *value = read_argc_and_value(line, 2);
	ssize_t index;
	
	if (index >= argc)
	{
		return NULL;
	}
	
	return argv[index];
}
