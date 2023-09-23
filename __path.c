#include "shell.h"

/**
 * path_exec_cmd -  Search In $PATH for executable command
 * @cmd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */
int path_exec_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}

/**
 * build_cmd - func for build command
 * @token: executable cmd
 * @value: cmd directory
 * Return: full path of parsed cmd (Success), fail (NULL)
 */
char *build_cmd(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * _getenv - func gets environment variable value by name
 * @name: name of environment variable
 * Return: environment variable value (Success), fail (NULL)
 */
char *_getenv(char *name_en_var)
{
	size_t name_len, value_len;
	char *val;
	int index, b, j;

	name_len = _strlen(name_en_var);
	for (index = 0 ; environ[index]; index++)
	{
		if (_strncmp(name_en_var, environ[index], name_len) == 0)
		{
			value_len = _strlen(environ[index]) - name_len;
			val = malloc(sizeof(char) * value_len);
			if (!val)
			{
				free(val);
				perror("unable to alloc");
				return (NULL);
			}

			b = 0;
			for (j = name_len + 1; environ[index][j]; j++, b++)
			{
				val[b] = environ[index][j];
			}
			val[b] = '\0';

			return (val);
		}
	}
	return (NULL);
}
