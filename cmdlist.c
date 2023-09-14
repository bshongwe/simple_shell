#include "command.h"


/**
 * add_cmd_end - func adds cmd at the end of list
 * @headptr: pointer to address of first list node
 * @cmd: cmd to add to list
 * Return: If memory allocation fails, return NULL. Otherwise, return the
 * address of the new node
 */
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd)
{
	cmdlist_t *new;

	if (!headptr)
		return (NULL);
	if (*headptr)
		return (add_cmd_end(&((*headptr)->next), cmd));

	new = malloc(sizeof(cmdlist_t));
	if (!new)
		return (NULL);

	new->next = NULL;
	new->tree = NULL;

	new->tokens = tokenize(cmd);
	if (!new->tokens)
	{
		free(new);
		return (NULL);
	}
	*headptr = new;

	return (new);
}

/**
 * del_cmd - func removes cmd from cmd list
 * @headptr: first node
 * @index: arg passed
 * Return: address of deleted node
 */
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index)
{
	cmdlist_t *old;

	if (!(headptr && *headptr))
		return (NULL);
	if (index)
		return (del_cmd(&((*headptr)->next), index - 1));

	old = *headptr;
	*headptr = (*headptr)->next;
	free_cmdtree(&(old->tree));
	free_tokens(&(old->tokens));
	free(old);

	return (old);
}

/**
 * pop_cmd - func removes node and retrieve node tokens
 * @headptr: first node
 * Return: command tokens
 */
char **pop_cmd(cmdlist_t **headptr)
{
	cmdlist_t *pop;
	char **tokens;

	if (!(headptr && *headptr))
		return (NULL);

	pop = *headptr;
	tokens = pop->tokens;
	*headptr = (*headptr)->next;

	free_cmdtree(&(pop->tree));
	free(pop);

	return (tokens);
}

/**
 * free_cmdlist - func frees linked list and sets head to NULL
 * @headptr: first node
 * Return: void
 */
void free_cmdlist(cmdlist_t **headptr)
{
	if (headptr && *headptr)
	{
		free_cmdlist(&((*headptr)->next));
		free_cmdtree(&((*headptr)->tree));
		free_tokens(&((*headptr)->tokens));
		free(*headptr);
		*headptr = NULL;
	}
}