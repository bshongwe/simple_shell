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

	tokens = malloc(sizeof(char *) * (count(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		tok = str;

		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}

		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		token[count][str - tok] = '\0';
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

/**
 * tokenize_noquote - func splits string into tokens
 * @str: input string
 * Return: tokens string array (Success), malloc fail (NULL)
 */
char **tokenize_noquote(const char *str)
{
	const char *tok;
	char **tokens;
	size_t count;

	if (!str)
	{
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * (count_token_noquote(str) + 1));
	if (!tokens)
	{
		return (NULL);
	}

	for (conut = 0; *str; ++count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok = str;
		do {
			++str;
		} while (*str && !_isspace(*str));

		tokens[count] = memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	return (tokens);
}

/**
 * count_tokens - func counts num of tokens in str after dequote
 * @str: input string
 * Return: str len (count)
 */
size_t count_tokens(const char *str)
{
	size_t count;
	quote_state_t state;

	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
			{
				str += quote_state_len(str + 1, state) + 1;
			}
			else
			{
				str += quote_state_len(str, state);
			}

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
			{
				++str;
			}
		}
	}
	return (count);
}
