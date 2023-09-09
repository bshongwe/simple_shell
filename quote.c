/* quote header */

/**
 * quote_state_len - func gets length of specific state
 * @str: string
 * @state: state
 * Return: matching c state
 */
size_t quote_state_len(const char *str, quote_state_t state)
{
	return (quote_state_f(state)(str, NULL));
}

/**
 * quote_state_f - func gets function of specific state
 * @s: state
 * Return: matching c state
 */
quote_state_fp quote_state_f(quote_state_t s)
{
	switch (s)
	{
		case QUOTE_NONE:
			return (_quote_state_none);
		case QUOTE_WORD:
			return (_quote_state_word);
		case QUOTE_DOUBLE:
			return (_quote_state_double);
		case QUOTE_SINGLE:
			return (_quote_state_single);
		case QUOTE_ESCAPE:
			return (_quote_state_escape);
	}
	return (NULL);
}

/**
 * quote_state - func gets state of specific character
 * @c: character
 * Return: matching c state
 */
quote_state_t quote_state(char c)
{
	if (_isspace(c))
	{
		return (QUOTE_NONE);
	}
	if (c == '"')
	{
		return (QUOTE_DOUBLE);
	}
	if (c == '\'')
	{
		return (QUOTE_SINGLE);
	}
	if (c == '\\')
	{
		return (QUOTE_ESCAPE);
	}
	return (QUOTE_WORD);
}
