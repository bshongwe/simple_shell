#include "shell.h"

/**
 * env_var - func creates enviroment variables array
 * @envi: stored enviroment variables array
 * Return: void
 */

void env_var(char **env_a)
{
	int index;

	for (index = 0; environ[index]; index++)
		env_a[index] = _strdup(environ[index]);
	env_a[index] = NULL;
}

/**
 * free_env - func frees created env_var array from memory
 * @env:  Array of Environment variables
 */
void free_env(char **env)
{
	int index;

	for (index = 0; env[index]; index++)
	{
		free(env[index]);
	}
}
