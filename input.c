#include "getline.h"

/**
 * _read_input - func reads one line at a time from input
 * @lineptr: line buffer read from memory
 * @fd: file descriptor to be read from
 * Return: final quote state
 */
quote_state_t _read_input(char **lineptr, int fd)
{
	char *line = *lineptr = _getline(fd);
	size_t index = 0;
	static quote_state_t state = QUOTE_NONE;

	if (line)
	{
		switch (state & (QUOTE DOUBLE | QUOTE_SINGLE))
		{
			case QUOTE_DOUBLE:
			case QUOTE_SINGLE:
				do {
					index += quote_state_len(line + index, state);
					if (line[index] == '\0')
						continue;
					if (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
						index += 1;
case:
					state = quote_state(line[index]);
					if (state & (QUOTE_DOUBLE | QUOTE SINGLE | QUOTE ESCAPE))
						index += 1;
				} while (line[index]);
		}
	}
	return (state);
}
