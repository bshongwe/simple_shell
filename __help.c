#include "builtins.h"

/**
 * __help - func displays builtin cmd prompts
 * @info: shell info
 * Return: status (Success)
 */
int __help(struct info *info)
{
	size_t len = 0;
	const builtin_t *bp = NULL;
	const char *desc = NULL;
	const char *args = NULL;

	if (*args)
	{
		info->status = EXIT_FAILURE;
		while (*args)
		{
			bp = get_builtin(*args);
			if (bp)
			{
				write(STDOUT_FILENO, bp->name, _strlen(bp->name));
				write(STDOUT_FILENO, ": ", 2);
				write(STDOUT_FILENO, bp->help, _strlen(bp->help));
				write(STDOUT_FILENO, "\n", 1);
				for (desc = bp->desc; (len = _strlen(desc)); desc += len + 1)
				{
					write(STDOUT_FILENO, "    ", 4);
					write(STDOUT_FILENO, desc, len);
					write(STDOUT_FILENO, "\n", 1);
				}
				info->status = EXIT_SUCCESS;
			}
			args += 1;
		}
		if (info->status == EXIT_FAILURE)
			perrorl_default(*info->argv,
					info->lineno, "No matching topics", *info->tokens,	*(args - 1), NULL);
		return (info->status);
	}
	info->status = EXIT_SUCCESS;
	for (bp = get_builtins(); bp->name; bp += 1)
	{
		write(STDOUT_FILENO, bp->help, _strlen(bp->help));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (info->status);
}
