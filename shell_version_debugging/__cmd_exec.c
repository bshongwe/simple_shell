#include "shell.h"

/**
 * __cd - func excecutes change directory cmd
 * @cmd: parsed cmd
 * @st: previous status of executed cmd
 * Return: Success (0), fail (1),
 * except for no OLDPWD
 */
int __cd(char **cmd, __attribute__((unused))int st)
{
	int val = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
	{
		val = chdir(getenv("HOME"));
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		val = chdir(getenv("OLDPWD"));
	}
	else
		val = chdir(cmd[1]);

	if (val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (val != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * history_print - func prints user input history
 * @c: parsed cmd
 * @st: previous executed cmd status
 * Return: Success (0), fail (-1)
 */
int history_pr(__attribute__((unused))char **c, __attribute__((unused))int st)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count_a = 0;
	char *_a;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		count_a++;
		_a = _itoa(count_a);
		PRINT(_a);
		free(_a);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

/**
 * pr_env - func displays env var
 * @cmd: parsed cmd
 * @st: previous status of executed cmd
 * Return: Always 0 (Success)
 */
int pr_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
	size_t index;
	int len;

	for (index = 0; environ[index] != NULL; index++)
	{
		len = _strlen(environ[index]);
		write(1, environ[index], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * echo_bltn - func executes echo cmd cases
 * @st: previous executed cmd status
 * @cmd: parsed cmd
 * Return: Always 1, or execute echo
 */
int echo_bltn(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_int(st);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
	{
		return (0);
	}

	return (1);
}

