#include "dict.h"

/**
 * get_dict_node - func retrieves specific node using key
 * @head: dict
 * @key: entry key
 * Return: node or NULL
 */
dict_t *get_dict_node(dict_t *head, const char *key)
{
	if (!head)
	{
		return (NULL);
	}
	if (!_strcmp(head->key, key))
	{
		return (head);
	}
	return (get_dict_node(head->next, key));
}

/**
 * add_dict_node_end - func add node to linked list
 * @headptr: dict pointer
 * @key: specific entry key
 * @val: specific entry val
 * Return: list pointer
 */
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val)
{
	dict_t *new;

	if (!headptr)
	{
		return (NULL);
	}

	if (*headptr)
	{
		return (add_dict_node_end(&((*headptr)->next), key, val));
	}

	new = malloc(sizeof(dict_t));
	if (!new)
	{
		return (NULL);
	}

	new->key = _strdup(key);
	new->val = _strdup(val);
	new->next = NULL;

	*headptr = new;
	return (new);
}

/**
 * del_dict_node - func deletes specific node
 * @headptr: dict pointer
 * @key: specific entry key
 * Return: list pointer
 */
dict_t *del_dict_node(dict_t **headptr, const char *key)
{
	dict_t *tmp;

	if (!(headptr && *headptr))
	{
		return (NULL);
	}
	if (!_strcmp((*headptr)->key, key))
	{
		tmp = *headptr;
		(*headptr) = tmp->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
	else
	{
		del_dict_node(&((*headptr)->next), key);
	}
	return (*headptr);
}

/**
 * free_dict - func frees linked list and sets head to NULL
 * @headptr: first list node
 * Return: void
 */
void free_dict(dict_t **headptr)
{
	if (!headptr)
	{
		return;
	}
	free_dict(&((*heaptr)->next));
	free((*headptr)->key);
	free((*headptr)->val);
	free(*headptr);
	*headptr = NULL;
}

/**
 * get_dict_val - func fetches value from dictionary
 * @head: dict
 * @key: entry key
 * Return: entry key
 */
char *get_dict_val(dic_t *head, const char *key)
{
	if (!key)
	{
		return (NULL);
	}

	while (head)
	{
		if (!_strcmp(head->key, key))
		{
			return (head->val);
		}
		head = head->next;
	}

	return (NULL);
}
