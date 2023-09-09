#include "command.h"

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
		free_cmdlist(&((*headptr)->tokens));
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
 * @headptr: first input node
 * Return: cmd tokens (Success)
 */
char **pop_cmd(cmdlist_t **headptr)
{
	char **tokens;
	cmdlist_t *pop;

	if (!(headptr && *headptr))
	{
		return (NULL);
	}

	pop = *headptr;
	tokens = pop->tokens;
	*headptr = (*headptr)->next;

	free_cmdtree(&(pop->tree));
	free(pop);

	return (tokens);
}

/**
 * del_cmd - func removes cmd from cmd list
 * @headptr: first input node
 * @index: argument input
 * Return: address of node
 */
cmdlist_t *del_cmd(cmdlist_t **headptr, sie_t index)
{
	cmdlist *old;

	if (!(headptr && *headptr))
	{
		return (NULL);
	}
	if (index)
	{
		return (del_cmd(&((*headptr)->next), index - 1));
	}

	old = *headptr;
	*headptr = (*headptr)->next;
	free_cmdtree(&(old->tree));
	free_tokens(&(old->tokens));
	free(old);

	return (old);
}
