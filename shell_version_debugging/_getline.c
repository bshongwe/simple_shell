#include "shell.h"

/**
 * hashtag_handler - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int index;

	for (index = 0; buff[index] != '\0'; index++)
	{
		if (buff[index] == '#' && buff[index - 1] == ' ' && buff[index + 1] == ' ')
		{
			buff[index] = '\0';
		}
	}
}

/**
 * enter - func handles newline char input
 * @string: string input
 * Return: empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * space - func modifies string input to remove preceeding whitespaces
 * @str: string input
 * Return: modified string
 */
char *space(char *str)
{
	int index, b = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (index = 0; str[index] == ' '; index++)
		;
	for (; str[index + 1] != '\0'; index++)
	{
		buff[b] = str[index];
		b++;
	}
	buff[b] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}

/**
 * _getline - func reads input from std input by user
 * Return: input on buffer
 */
char *_getline()
{
	int index, buff_rd, buff_size = BUFSIZE;
	char c = 0, *buffer, *buf;

	buffer = malloc(buff_size);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (index = 0; c != EOF && c != '\n'; index++)
	{
		fflush(stdin);
		buff_rd = read(STDIN_FILENO, &c, 1);
		if (buff_rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[index] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (index >= buff_size)
		{
			buffer = realloc(buffer, (buff_size + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[index] = '\0';
	buf = space(buffer);
	free(buffer);
	hashtag_handler(buf);
	return (buf);
}
