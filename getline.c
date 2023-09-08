#include "getline.h"

/**
 * char *_getline - func reads input line
 * @fd: memory read file descriptor
 * Return: next input line (Success), error or more lines (NULL)
 */
char *_getline(const int fd)
{
	char *line = NULL;
	static buf_table_t table;
	size_t size = 0;
	ssize_t eol = 0, n_read = 0;
	buf_t *buf = _getline_buf(&table, fd);
	
	if (fd == -1)
	{
		return (NULL);
	}
	
	buf _getline_buf(&table, fd);
	if (buf == NULL)
	{
		return (NULL);
	}

	while (1)
	{
		n_read = read(fd, buf->data, BUF_SIZE);
		if (n_read == -1 || n_read == 0)
		{
			break;
		}

		eol = 

	line = n_read;
	return (line);
}

/**
 * _getline_buf - func creates, gets and deletes buffers in memory
 * @table: file descriptor index buffers
 * @fd: file descriptor
 * Return: specific fd buffer pointer (Success), error (NULL)
 */
static buf_t *_getline_buf(buf_table_t *table, const int fd)
{
	size_t index =fd % GETLINE_TABLE_SIZE;
	buf_table_node_t *item = NULL;

	if (table)
	{
		item = table->nodes[index];
		while (item && item->fd != fd)
		{
			item = item->next;
		}
	}
	return (item ? &item->buf : NULL);
}

/**
 * getline_next - func reads input line and returns pointer
 * @buf: static buffer pointer
 * @line: line address pointer
 * @size: line size address pointer
 * @n: buffer char copies
 * Return: input line pointer (Success), memcpy fail (NULL)
 */
static char *_getline_next(buf, char **line, size_t *size, size_t n)
{
	char *tem = NULL;

	if (*line)
	{
		temp = realloc(*line, *size, *size + n);
	}
	else
		temp = malloc(n + 1);

	if (temp)
	{
		*line = temp;

		if (*size)
			*size -= 1;

		_memcpy(*line + *size, buf->next, n);
		*size += n;

		(*line)[*size] = '\0';
		*size += 1;
	}
	else
	{
		free(*line);
		*line = NULL;
		*size = 0;
	}
	return (*line);
}

/**
 * _realloc - func returns new buffer mem address pointer
 * @old: buffer pointer
 * @old_size: current buffer size
 * @new_size: new buffer size
 * Return: new  buffer pointer (Success), memcpy fail (Null)
 */
static void *_realloc(void *old, size_t oldsize, size, size_t new_size)
{
	void *new = NULL;

	if (old)
	{
		if (new_size)
		{
			new = malloc(new_size);
			if (new)
				_memcpy(new, old, old_size < new_size ? old_size : new_size);
			free(old);
		}
		else
			free(old);
	}
	return (new);
}
