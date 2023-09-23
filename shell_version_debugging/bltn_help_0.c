#include "shell.h"

/**
 * pr_help - func prints help for builtin cmds
 * @cmd: parsed command
 * @st: previous executed cmd status
 * Return: Success (0)
 */
int pr_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
	{
		help_all();
	}
	else if (_strcmp(cmd[1], "alias") == 0)
	{
		help_alias();
	}
	else if (_strcmp(cmd[1], "cd") == 0)
	{
		help_cd();
	}
	else if (_strcmp(cmd[1], "exit") == 0)
	{
		help_exit();
	}
	else if (_strcmp(cmd[1], "env") == 0)
	{
		help_env();
	}
	else if (_strcmp(cmd[1], "setenv") == 0)
	{
		help_setenv();
	}
	else if (_strcmp(cmd[1], "unsetenv") == 0)
	{
		help_unsetenv();
	}
	else if (_strcmp(cmd[1], "help") == 0)
	{
		help_help();
	}
	return (0);
}

/**
 * help_unsetenv - func prints information "shellby" builtin command
 * 'unsetenv'
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_all - Displays all possible builtin shellby commands
 */
void help_all(void)
{
	char *msg = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
