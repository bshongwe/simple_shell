#include "command.h"

/**
 * free_cmdtree - Frees a binary tree and sets root to NULL.
 * @rootptr: A pointer to root.
 * Return: NULL.
 */

void free_cmdtree(cmdtree_t **rootptr)
{
	if (rootptr && *rootptr)
	{
		free_cmdtree(&((*rootptr)->success));
		free_cmdtree(&((*rootptr)->failure));
		(*rootptr)->tokens = NULL;
		(*rootptr) = NULL;
	}
}

/**
 * cmd_to_tree - Construct a binary tree of commands.
 * @tokens: The command to parse.
 * Return: NULL if memory alloc fails, otherwise return new tree's adrress.
 */

cmdtree_t *cmd_to_tree(const char * const *tokens __attribute__((unused)))
{
	return (NULL);
}
