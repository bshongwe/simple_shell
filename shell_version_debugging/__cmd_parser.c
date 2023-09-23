#include "shell.h"

/**
 * parse_stdn_cmd - func parses cmd recieved from stdin
 * @input: string input from stdin
 * Return: arg parsed strings
 */
char **parse_stdn_cmd(char *input)
{
	char **arg_s;
	char *arg_1;
	int index;
	int buff_size = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
	{
		exit(0);
	}
	if (input == NULL)
	{
		return (NULL);
	}
	arg_s = malloc(sizeof(char *) * buff_size);
	if (!arg_s)
	{
		free(arg_s);
		perror("hsh");
		return (NULL);
	}
	arg_1 = _strtok(input, "\n\t\r\a ");
	for (index = 0; arg_1; index++)
	{
		arg_s[index] = arg_1;
		arg_1 = _strtok(NULL, "\n\t\r\a ");
	}
	arg_s[index] = NULL;

	return (arg_s);
}
