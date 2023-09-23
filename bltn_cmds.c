#include "shell.h"

/**
 * pop_bltn - func populates built-in cmds
 * @cmd: parsed cmd strings array
 * @st: previous execution status
 * Return: Success (0), failure (-1)
 */
int pop_bltn(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", __cd},
		{"env", pr_env},
		{"help", pr_help},
		{"echo", echo_bltn},
		{"history", history_pr},
		{NULL, NULL}
	};
	int index = 0;

	while ((built_in + index)->command)
	{
		if (_strcmp(cmd[0], (built_in + index)->command) == 0)
		{
			return ((built_in + index)->function(cmd, st));
		}
		index++;
	}
	return (-1);
}

/**
 * check_builtin - func verifies parsed cmd
 * @cmd: parsed cmd
 * Return: Success (0), fail (-1)
 */
int check_bltn(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int index = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + index)->command)
	{
		if (_strcmp(cmd[0], (fun + index)->command) == 0)
			return (0);
		index++;
	}
	return (-1);
}

/**
 * exit_bltn - Exit Status for built-in commands
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */
void exit_bltn(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, index = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][index])
	{
		if (_isalpha(cmd[1][index++]) != 0)
		{
			_prerror(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				_prerror(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);

		}
	}
}
