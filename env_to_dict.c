#include /* --> env header */

/**
 * _env_to_dict - func converts env into linked list
 * @tailptr: list tail pointer
 * @env: environment
 * Return: head (Success)
 */
env_t *_env_to_dict(env_t **tailptr, char **env)
{
	char *env_str;
	ssize_t key_len;
	env_t *tail;

	if (!*env)
	{
		return (*tailptr);
	}

	env_str = _strdup(*env);
	if (!env_str)
	{
		return (NULL);
	}

	key_len = _strchr(*env, '=');
	if (key_len == -1)
	{
		return (NULL);
	}

	env_str[key_len] = '\0';
	tail = add_dict_node_end(tailptr, env_str, env_str + key_len + 1);
	free(env_str);

	return (_env_to_dict(&tail, env + 1));
}

/**
 * env_to_dict - func creates linked list from env
 * @env: env input
 * Return: head from list
 */
env_t *env_to_dict(char **env)
{
	env_t *head = NULL;

	if (!_env_to_dict(&head, env))
	{
		free_dict(&head);
	}

	return (head);
}
