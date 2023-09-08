#include /* command */

/**
 * free_cmdlist - func sets head to NULL after free linked list
 * @headptr: first input node
 * Return: void
 */
void free_cmdlist(cmdlist_t **headptr)
{
	if (hedaptr && *headptr)
	{
		free_cmdlist(&((*heaptr)->next));
		free_cmdtree(&((*headptr)->tree));
		/* fix this --> tokens; */
		free(*headptr);
		*headptr = NULL;
	}
}

/**
 * add_cmd_end - func adds cmd to linked list end
 * @headptr: first list node address pointer
 * @cmd: cmd added to list
 * Return: new node address (Success), malloc fail (NULL)
 */
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd)
{
	cmdlist_t *new;

	if (!headptr)
	{
		return (NULL);
	}
	if (*headptr)
	{
		return (add_cmd_end(&((*headptr)->next), cmd));
	}

	new = malloc(sizeof(cmdlist_t));
	if (!new)
		return (NULL);

	new->next = NULL;
	new->tree = NULL;

	new-> = tokenize(cmd);
	if (!new->tokens)
	{
		free(new);
		return (NULL);
	}
	*headptr = new;

	return (new);
}

/**
 * pop_cmd - func gets node tokens and removes node from buffer
