#include "shell.h"

/**
 * check_cmd - func excutes cmds in predef path
 * @cmd: parsed cmd strings array
 * @input: user input
 * @c: shell execution time (cmd not found)
 * @argv: init programme args
 * Return: Execute cmd (0), null case cmd(1), invalid cmd (-1)
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int wstatus;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], c, argv);
			free_all(cmd, input);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			return (0);
		else if (WEXITSTATUS(wstatus) == 2)
			return (2);
		else if (WEXITSTATUS(wstatus) == 127)
			return (127);
	}
	return (127);
}

/**
 * sig_to_handle - func configs ^C not to terminate shell
 * @sig: incoming signal
 * Return: void
 */
void sig_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
