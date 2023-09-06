#include "builtins.h"

/**
 * __setenv - func set env vars and returns info->status
 * @info: args
 * Return: status (Success)
 */
int __setenv(info_t *info)
{
	char **args = info->tokens + 1, val;
	env_t *var;

	if (args[0])
	{
		if (args[1])
		{
			if (args[2])
			{
				perrorl("Excessive arguments.", *info->tokens, NULL);
				info->status = EXIT_FAILURE;
				return (info->status);
			}
			val = args[1];
		}
		else
		{
			val = "";
		}
		var = get_dict_node(info->env, args[0]);
		if (var)
		{
			free(var->val);
			var->val = _strdup(val);
		}
		else
			add_dict_node_end(&info->env, args[0], val);
		info->status = EXIT_SUCCESS;
	}
	else
		__env(info);
	return (info->status);
}
