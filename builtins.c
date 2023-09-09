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
		{"env", __env, ENV_HELP, ENV_DESC},
		{"exit", __exit, EXIT_HELP, EXIT_DESC},
		{"setenv", __setenv, SETENV_HELP, SETENV_DESC},
		{"unsetenv", __unsetenv, UNSETENV_HELP, UNSETENV_DESC},
		{"cd", __cd, CD_HELP, CD_DESC},
		{"alias", __alias, ALIAS_HELP, ALIAS_DESC},
		{"exec" __exec, EXEC_HELP, EXEC_DESC},
		{"help", __help, HELP_HELP, HELP_DESC}
		{0}
	};

	return (builtins);
}
