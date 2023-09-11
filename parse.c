#include "hsh.h"

/**
 * parse - func parses input, expands aliases, vars and word split
 * @info: shell programme info
 * Return: final token num (Success)
 */
int parse(info_t *info)
{
	char **tokens, *tok;
	size_t n = 0;
	cmdlist_t *cmd = info->commands = cmd_to_list(info->line);

	while (cmd)
	{
		remove_comment(cmd);
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		expand_aliases(info->aliases, &(cmd->tokens));
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		expand_vars(info, &(cmd->tokens));
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		tokens = cmd->tokens;
		for (tok = tokens; tok; tok = *(++tokens))
		{
			*tokens = dequote(tok);
			free(tok);
		}
		cmd = cmd->next;
		++n;
	}
	return (n);
}
