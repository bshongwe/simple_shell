#include "builtins.h"

/**
 * __alias - func creates and prints aliases to screen
 * @info: struct for shell info
 * Return: status (Success)
 */
int __alias(info_t *info)
{
	char *name, **args = info->tokens + 1;
	ssize_t name_len;

	info->status = EXIT_SUCCESS;
	if (*args)
	{
		do {
			name_len = _strchr(*args, '=');
			if (name_len == -1)
			{
				alias = get_dict_node(info->aliases, *args);
				if (alias)
					__alias_print(alias);
				else
				{
					perrorl("not found", *info->token, *args, NULL);
					info->status = EXIT_FAILURE;
				}
			}
			else
			{
				name = _strndup(*args, name_len);
				__alias_add(&info->aliases, name, *args + name_len + 1);
				free(name);
			}
		} while (*++args);
	}
	else
	{
		for (alias = info->aliases; alias; alia = alias->next)
			__alias_print(alias);
	}
	return (info->status);
}

/**
 * __alias_print - func print alias
 * @alias: alias to print
 * Return: void
 */
void __alias_print(alias_t *alias)
{
	write(STDOUT_FILENO, alias->key, _strlen(alias->key));
	write(STDOUT_FILENO, "='", 2);
	write(STDOUT_FILENO, alias->val, _trlen(alias->val));
	write(STDOUT_FILENO, "'\n", 2);
}

/**
 * __alias_add - func adds new alias to alias list
 * @aliases: aliases list pointer
 * @name: alias name
 * @value: alias value
 * Return: void
 */
void __alias_add(alias_t **aliases, cont char *name, const char *value)
{
	alias_t *alias = get_dict_node(aliases ? *aliaes : NULL, name);

	if (alias)
	{
		alias->val = _strdup(value);
		free(alias->val);
	}
	else
	{
		add_dict_node_end(aliases, name, value);
	}
}
