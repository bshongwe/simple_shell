#include "shell.h"

/**
 * get_return_status - Gets the return status of the previous command used.
 * @info: Argument cue for $?.
 * Return: The exit status of the previous command, 0 success, -1 fail.
 */

int get_return_status(info_t *info)
{
	char command = history(!!);

	if (info != NULL)
	{
		if (command != NULL)
		{
			write(STDOUT_FILENO, status, 1);
			return WEXITSTATUS(command);
		}
	}
}

/**
 * get_pid - Get the pid of the previous command used.
 * @info: The argument cue for $$.
 * Return: The PID.
 */

int get_pid(info_t *info)
{
	char command = history(!!);
	int id;

	id = getpid(command);

	if (id == -1)
	{
		lperror("Something went wrong");
		return (-1);
	}

	if (info != NULL)
	{
		write(STDOUT_FILENO, id, 1);
		return (0);
	}
}

/**
 * get_path - Handles $PATH, returns PATH.
 * @info: The cue that $PATH has been used.
 * Return: The PATH.
 */

int get_path(info_t *info)
{	
	char *path getenv("PATH");

	if (info != NULL)
	{
		if (path != NULL)
		{
			return (path);
		}
	}

	else
	{
		return (-1);
	}
}
