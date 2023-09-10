#include "list.h"

/**
 * str_to_list - Turn a string into a linked list.
 * @str: The string passed.
 * @delim: The delimiter passed.
 * Return: A pointer to list.
 */

list_t *str_to_list(const char *str, char delim)
{
	list_t *head = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	if (delim == NULL)
	{
		return (NULL);
	}

	if (_str_to_list(&head, str, delim) == NULL)
	{
		free_list(&head);
	}

	return (head);
}

/**
 * _str_to_list - Turn a string into a linked list (helper).
 * @tailptr: Pointer to the tail of the list.
 * @str: The string to be changed into a linked list.
 * @delim: The delimiter to devide the string into nodes.
 * Return: A pointer to the tail of the list.
 */

list_t *_str_to_list(list_t **tailptr, const char *str, char delim)
{
	list_t *tail;
	ssize_t len = _strchr(str, delim);

	if (len == -1)
	{
		len = _strlen(str);
	}

	tail = add_node_end(tailptr, NULL);
	if (tail == NULL)
	{
		return (NULL);
	}

	tail->str = _memdup(str, len + 1);
	if (tail->str == NULL)
	{
		return (NULL);
	}

	tail->str[len] = '\0';
	if (str[len] != NULL)
	{
		return (_str_to_list(&tail, str + len + 1, delim));
	}

	return (tail);
}
