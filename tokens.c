#include "tokens.h"

/**
 * tokenize - func splits string into tokens and dequote
 * @str: string input
 * Return: if malloc fails or if str is 0 or contains no tokens, return NULL,
 * otherwise, return array containing the tokens in str, terminated by NULL
 */
char **tokenize(const char *str)
{
	char **tokens;
	const char *tok;
	size_t count;
	quote_state_t state;

	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens(str) + 1));
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
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	return (tokens);
}

/**
 * count_tokens - func computes string len after dequoting
 * @str: string input
 * Return: Return str len after dequoting
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
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}
	}
	return (count);
}

/**
 * tokenize_noquote - func splits string into tokens
 * @str: string input
 * Return: if malloc fails or if str is 0 or contains no tokens, return NULL
 * otherwise, return an array containing the tokens in str, terminated by NULL
 */
char **tokenize_noquote(const char *str)
{
	char **tokens;
	const char *tok;
	size_t count;

	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens_noquote(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *str; ++count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok = str;
		do {
			++str;
		} while (*str && !_isspace(*str));

		tokens[count] = _memdup(tok, str - tok + 1);
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
 * count_tokens_noquote - func counts words in string
 * @str: string input
 * Return: if str is NULL, return -1, otherwise, return
 * number of words in str
 */
size_t count_tokens_noquote(const char *str)
{
	size_t tok_count;

	for (tok_count = 0; *str; ++tok_count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !_isspace(*str));
	}
	return (tok_count);
}

/**
 * free_tokens - func frees and nullifies strings array
 * @tokens: tokens array pointer
 */
void free_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
		return;

	tok = *tokens;
	if (!tok)
		return;

	while (*tok)
		free(*tok++);
	free(*tokens);

	*tokens = NULL;
}
