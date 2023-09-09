/* quote header */

/**
 * _quote_state_word - func gets length and next state
 * @str: input string
 * @state: state
 * Return: state length (Success)
 */
size_t _quote_state_word(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && !_isspace(*str) && !_isquote(*str))
	{
		++str, ++len;
	}
	if (state && *str)
	{
		*state = quote_state(*str);
	}
	return (len);
}

/**
 * _quote_state_none - func gets length and next state
 * @str: input string
 * @state: state
 * Return: state length (Success)
 */
size_t _quote_state_none(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (_isspace(*str))
	{
		++str, ++len;
	}
	if (state && *str)
	{
		*state = quote_state(*str);
	}
	return (len);
}

/**
 * _quote_state_double - func gets length and next state
 * @str: input string
 * @state: state
 * Return: state length (Success)
 */
size_t _quote_state_double(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '"')
	{
		++str, ++len;
	}
	if (state && *str)
	{
		*state = quote_state(*(str + 1));
	}
	return (len);
}

/**
 * _quote_state_single - func gets length and next state
 * @str: input string
 * @state: state
 * Return: state length (Success)
 */
size_t _quote_state_single(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '\'')
	{
		++str, ++len;
	}
	if (state && *str)
	{
		*state = quote_state(*(str + 1));
	}
	return (len);
}
