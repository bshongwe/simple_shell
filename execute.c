#include "hsh.h"
#include <sys/types.h>
#include <stdio.h>

/**
 * main - func gets and stores parent process ID and forks child process
 * @parent_pid: process ID of parent process
 * @child_pid: process ID of child process
 * @buf: Buffer used to format output strings
 * Return: fork success (1), fork fail (1)
 */

int main(void)
{
	pid_t parent_pid, child_pid;
	char buf[256];

	parent_pid = getpid();
	child_pid = fork();

	if (child_pid < 0)
	{		
		write(STDERR_FILENO, "Fork failed\n", 12);
		return 1;
	}
	else if (child_pid == 0)
	{
		int len = snprintf(buf, sizeof(buf), "child PID: %d\n", getpid());
		write(STDOUT_FILENO, buf, len);
		len = snprintf(buf, sizeof(buf), "parent PID: %d\n", getppid());
		write(STDOUT_FILENO, buf, len);
	}
	else
	{
		int len = snprintf(buf, sizeof(buf), "parent PID: %d\n", getpid());
		write(STDOUT_FILENO, buf, len);
		len = snprintf(buf, sizeof(buf), "child PID: %d\n", child_pid);
		write(STDOUT_FILENO, buf, len);
	}

	return 0;
}


/**
  * execute - func executes cmd
  * @info: args passed
  * Return: status
  */
int execute(info_t *info)
{
	const builtin_t *builtin = get_builtin(*info->tokens);

	if (builtin)
	{
		return (builtin->f(info));
	}
	if (_strchr(*info->tokens, '/') == -1)
	{
		free_list(&info->path);
		info->path = str_to_list(get_dict_val(info->env, "PATH"), ':');
		info->exe = search_path(info, info->path);
	}
	else
	{
		info->exe = _strdup(*info->tokens);
	}
	if (info->exe && access(info->exe, X_OK) == 0)
	{
		return (_execute(info));
	}
	if (info->exe)
	{
		perrorl_default(*info->argv, info->lineno, "Permission denied",
				*info->tokens, NULL);
		info->status = 126;
	}
	else
	{
		perrorl_default(*info->argv, info->lineno, "not found",
				*info->tokens, NULL);
		info->status = 127;
	}
	return (info->status);
}

/**
 * _execute - func forks and executes the current cmd
 * @info: shell information
 * Return: exit status of the child process
 */
int _execute(info_t *info)
{
	char *exe, **argv, **env;

	switch (fork())
	{
	case 0:
		exe = info->exe;
		argv = info->tokens;
		env = dict_to_env(info->env);

		info->exe = NULL;
		info->tokens = NULL;
		free_info(info);

		execve(exe, argv, env);
		perror(*argv);

		if (info->file)
			close(info->fileno);

		free(exe);
		free_tokens(&argv);
		free_tokens(&env);
		exit(EXIT_FAILURE);
		break;
	case -1:
		perrorl_default(*info->argv, info->lineno, "Cannot fork", NULL);
		info->status = 2;
		break;
	default:
		wait(&info->status);
		info->status = WEXITSTATUS(info->status);
		break;
	}
	free(info->exe);
	info->exe = NULL;

	return (info->status);
}
