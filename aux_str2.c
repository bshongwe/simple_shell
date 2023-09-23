#include "main.h"

/**
 *  * _strtok - func splits string using delimiter
 *   * @str: input string
 *    * @delim: delimiter
 *      * Return: string splited
 *       */
char *_strtok(char str[], const char *delim)
{
		static char *splitted, *str_end;
			char *str_start;
				unsigned int i, bool;

					if (str != NULL)
							{
										if (cmp_chars(str, delim))
														return (NULL);
												splitted = str; /*first address*/
														i = _strlen(str);
																str_end = &str[i]; /*last address*/
																	}
						str_start = splitted;
							if (str_start == str_end) /*end*/
										return (NULL);

								for (bool = 0; *splitted; splitted++)
										{
													/*breaks loop, finds next token*/
													if (splitted != str_start)
																	if (*splitted && *(splitted - 1) == '\0')
																						break;
															/*replaces delimiter for null char*/
															for (i = 0; delim[i]; i++)
																		{
																						if (*splitted == delim[i])
																										{
																															*splitted = '\0';
																																			if (splitted == str_start)
																																									str_start++;
																																							break;
																																										}
																								}
																	if (bool == 0 && *splitted) /*Str != Delim*/
																					bool = 1;
																		}
									if (bool == 0) /*Str == Delim*/
												return (NULL);
										return (str_start);
}

/**
 *  * cmp_chars - func compares string chars
 *   * @str: input string
 *    * @delim: delimiter
 *      * Return: 1 if are equals, 0 if not equal
 *       */
int cmp_chars(char str[], const char *delim)
{
		unsigned int i, j, k;

			for (i = 0, k = 0; str[i]; i++)
					{
								for (j = 0; delim[j]; j++)
											{
															if (str[i] == delim[j])
																			{
																								k++;
																												break;
																															}
																	}
									}
				if (i == k)
							return (1);
					return (0);
}

/**
 *  * _isdigit - func defines if string is a number
 *    * @s: input string
 *     * Return: 1 if string is a number, 0 in other case
 *      */
int _isdigit(const char *s)
{
		unsigned int i;

			for (i = 0; s[i]; i++)
					{
								if (s[i] < 48 || s[i] > 57)
												return (0);
									}
				return (1);
}

/**
 *  * _strlen - func returns string lenght
 *   * @s: type char pointer
 *    * Return: Always 0
 *     */
int _strlen(const char *s)
{
		int len;

			for (len = 0; s[len] != 0; len++)
					{
							}
				return (len);
}

/**
 *  * _strdup - func duplicates str in the heap memory
 *   * @s: Type char pointer str
 *    * Return: duplicated str
 *     */
char *_strdup(const char *s)
{
		char *new;
			size_t len;

				len = _strlen(s);
					new = malloc(sizeof(char) * (len + 1));
						if (new == NULL)
									return (NULL);
							_memcpy(new, s, len + 1);
								return (new);
}
