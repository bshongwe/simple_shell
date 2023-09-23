#include "shell.h"

/**
 * file_read - func reads cmds from arg file
 * @file: cmds file
 * @argv: passed args
 * Return: Success (0), fail (-1)
 */
void file_read(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		error_file(argv, count);
		exit(127);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		treat_file(line, count, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * file_treat - func parses cmds handles their execution
 * @line: file line
 * @count: error counter
 * @fp: file desc
 * @argv: cmd line args
 * Return: void
 */
void file_treat(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = parse_cmd(line);
	if (_strncmp(cmd[0], "exit", 4) == 0)
	{
		exit_bltn_file(cmd, line, fp);
	}
	else if (check_builtin(cmd) == 0)
	{
		stat = handle_builtin(cmd, stat);
		free(cmd);
	}
	else
	{
		stat = check_cmd(cmd, line, count, argv);
		free(cmd);
	}
}

/**
 * exit_bltn_file - func for file input exit status
 * @line: file line
 * @cmd: parsed cmd
 * @fd: file desc
 * Return: void
 */
void exit_bltn_file(char **cmd, char *line, FILE *fd)
{
	int status;
	int index = 0;

	if (cmd[index] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][index])
	{
		if (_isalpha(cmd[1][index++]) < 0)
		{
			perror("invalid number");
		}
	}
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
