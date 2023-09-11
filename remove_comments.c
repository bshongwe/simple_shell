#include "hsh.h"

/**
 * remove_comments - Removes comments (#) from a command.
 * @cmd: Pointer to ther cmd process.
 * Return: Nothing.
 */

void remove_comments(cmdlist_t *cmd)
{
	char **tokens, **new, *tmp;

	for (tokens = cmd->tokens; *tokens; ++tokens)
	{
		if (**tokens == '#')
		{
			tmp = *tokens;
			*tokens = NULL;
			new = arrdup(cmd->tokens);
			*tokens = tmp;
			free_tokens(&(cmd->tokens));
			cmd->tokens = new;
			free_cmdlist(&(cmd->next));
			return;
		}
	}
}
