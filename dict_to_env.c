#include "env.h"

/**
 * dict_to_env - func creats env linked list
 * @head: arg input
 * Return: list pointer
 */
char **dict_to_env(env_t *head)
{
	char **env;
	size_t len = 0;
	env_t *tmp = head;

	while (tmp)
	{
		++len, tmp = tmp->next;
	}

	env = malloc(sizeof(char *) * (len + 1));
	if (!env)
	{
		return (NULL);
	}

	for (len = 0; head; head = head->next)
	{
		env[len++] = strjoin(NULL, "=", head->key, head->val);
		env[len] = NULL;
	}

	return (env);
}
