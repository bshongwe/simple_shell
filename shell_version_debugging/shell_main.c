#include "shell.h"

/**
 * main - Programme entry point
 * @argc: argc input
 * @argv: argv input
 * Return: Returns condition
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd, **commands;
	int count = 0, index, condition = 1, stat = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, sig_to_handle);
	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		history(input);
		commands = separator(input);
		for (index = 0; commands[index] != NULL; index++)
		{
			cmd = parse_cmd(commands[index]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, input, argv, count, stat);
			}
			else if (check_builtin(cmd) == 0)
			{
				stat = handle_builtin(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = check_cmd(cmd, input, count, argv);
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&stat);
	}
	return (stat);
}
