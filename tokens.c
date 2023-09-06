#include "tokens.h"

/**
 * tokenize - func splits string into tokens and dequote
 * @str: input string to tokenize
 * Return: string array tokens (Success), fail (0),
 * no tokens (NULL)
 */
char **tokenize(const char *str)
{
	const char *tok;
	char **tokens;
	size_t count;
	quote_state_t state;

	if (!str)
		return (NULL);

	tokens =malloc(sizeof(char *) * (count(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		/* will fill this later */
	}
	tokens[count] = NULL;

	return (tokens);
}

/**
 * free_tokens - func free string array from memory
 * @tokens: tokens array pointer
 * Return: void
 */
void free_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
	{
		return;
	}

	tok = *tokens;

	if (!tok)
	{
		free(*tok++);
	}
	free(*tokens);

	*tokens = NULL;
}

/* Middleware to follow */
