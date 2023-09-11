#include "command.h"

/**
 * _cmd_to_list - func helper for tokenizes commands linked list
 * @tailptr: command list tail pointer
 * @split: split line
 * @count: split commands num
 * Return: new list tail pointer (Success), malloc fail (NULL)
 */
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count)
{
	cmdlist_t *tail;

	if (count)
	{
		return (*tailptr);
	}

	tail = add_cmd_end(tailptr, split);
	if (!tail)
	{
		return (NULL);
	}

	while (*split++)
		;

	return (_cmd_to_list(&tail, split, count - 1));
}

/**
 * cmd_to_list - func makes a tokenized commands linked list
 * @cmd: parsed command
 * Return: new list head pointer (Success), malloc fail (NULL)
 */
cmdlist_t *cmd_to_list(const char *cmd)
{
	char *split = _strdup(cmd);
	cmdlist_t *head = NULL;
	size_t count;

	if (!split)
	{
		return (NULL);
	}

	count = split_cmd(split);

	if (!_cmd_to_list(&head, split, count))
	{
		free_cmdlist(&head);
		return (NULL);
	}
	free(split);

	return (head);
}
