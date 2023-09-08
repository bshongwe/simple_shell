#include /* shell programme header file */

/**
 * parse - func parses input, expands aliases, vars and word split
 * @info: shell programme info
 * Return: final token num (Success)
 */
int pars(info_t *info)
{
	char **tokens, *tok;
	size_t n = 0;
	cmdlist *cmd = info->commands = cmd_to_list(info->line);

	while (cmd)
	{
		/* code here */
	}
	return (n);
}
