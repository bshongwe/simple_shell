#include "builtins.h"

/**
 * get_builtin - func fetches builtin by name
 * @name: builtin cmd name
 * Return: builtin pointer (Success), no match found (NULL)
 */
const builtin_t *get_builtin(const char *name)
{
	const builtin_t *builtin = NULL;

	for (builtin = get_builtins(); builtin->name; builtin += 1)
	{
		if (_strcmp(name, builtin->name) == 0)
		{
			return (builtin);
		}
	}
	return (NULL);
}

/**
 * get_builtins - func fetches builtins from stat-alloc
 * Return: NULL-terminated builtin stat-alloc array pointer
 */
const builtin_t *get_builtins(void)
{
	static builtin_t builts[] = {
		{"env", __env},
		{"exit", __exit},
		{"setenv", __setenv},
		{"unsetenv"},
		{0}
	};

	return (builtins);
}
