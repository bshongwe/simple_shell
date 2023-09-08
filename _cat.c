#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to STDOUT_FILENO.
 * @filename: The text file to be read and printed to STDOUT.
 * @letters: The number of letters it should read and printed.
 * Return: The actual number of letters that could read and printed.
 */

ssize_t _cat(const char *filename, size_t letters)
{
	int file;
	char *buff;
	ssize_t readBytes, writeBytes;

	if (filename == NULL)
	{
		return (0);
	}
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		return (0);
	}
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(file);
		return (0);
	}
	readBytes = read(file, buff, letters);
	if (readBytes == -1)
	{
		free(buff);
		close(file);
		return (0);
	}
	writeBytes = write(STDOUT_FILENO, buff, readBytes);
	if (writeBytes == -1 || writeBytes != readBytes)
	{
		free(buff);
		close(file);
		return (0);
	}
	free(buff);
	close(file);
	return (writeBytes);
}
