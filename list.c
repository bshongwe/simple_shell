#include "list.h"

/**
 * free_list - func fress linked list and sets head to NULL
 * @headptr: head list node
 * Return: void
 */
void free_list(list_t **headptr)
{
	if (!*headptr)
	{
		return;
	}

	free_list(&((*headptr)->next));
	free((*headptr)->str);
	free(*headptr);
	*headptr = NULL;
}

/**
 * str_to_list - Turn a string into a linked list.
 * @str: The string passed.
 * @delim: The delimiter passed.
 * Return: A pointer to list.
 */

list_t *str_to_list(const char *str, char delim)
{
	list_t *head = NULL;

	if (!str)
	{
		return (NULL);
	}

	if (!_str_to_list(&head, str, delim))
	{
		free_list(&head);
	}

	return (head);
}

/**
 * add_node - func inserts string at list head
 * @headptr: first list node pointer address
 * @str: string input
 * Return: address of new node (Success), malloc fail (NULL)
 */
list_t *add_node(list_t **headptr, const char *str)
{
	list_t *new;

	if (!headptr)
	{
		return (NULL);
	}

	new = malloc(sizeof(list_t));
	if (!new)
	{
		return (NULL);
	}

	new->str = _strdup(str);
	new->next = *headptr;

	*headptr = new;

	return (new);
}

/**
 * add_node_end - func inserts string at list tail
 * @headptr: first list pointer address
 * @str: string input
 * Return: address of new node node (Success), malloc fail (NULL)
 */
list_t *add_node_end(list_t **headptr, const char *str)
{
	list_t *new;

	if (!headptr)
	{
		return (NULL);
	}

	if (*headptr)
	{
		return (add_node_end(&((*headptr)->next), str));
	}

	new = malloc(sizeof(list_t));
	if (!new)
	{
		return (NULL);
	}

	new->str = _strdup(str);
	new->next = *headptr;

	*headptr = new;

	return (new);
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
	if (!tail)
	{
		return (NULL);
	}

	tail->str = _memdup(str, len + 1);
	if (!tail->str)
	{
		return (NULL);
	}

	tail->str[len] = '\0';

	if (str[len])
	{
		return (_str_to_list(&tail, str + len + 1, delim));
	}

	return (tail);
}