#include "main.h"

/**
 * print_environment - Prints the environment.
 * Return: Void.
 */

void print_environment(void)
{
	int i = 0;
	size_t length;

	while (environ[i] != NULL)
	{
		length = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		i++;
	}
}

/**
 * set_environment_variable - Set/creates an environment variable.
 * @variable: The variable name.
 * @value: The value of the variable.
 * Return: Void.
 */

void set_environment_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		perror("Failed to set environment variable");
	}
}

/**
 * unset_environment_variable - Unsets/deletes a set enviroment variable.
 * @variable: The variable name to be unset.
 * Return: Void.
 */

void unset_environment_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		perror("Failed to unset environment variable");
	}
}

/**
 * change_directory - Changes the current directory.
 * @directory: The directory name.
 * Return: Void.
 */

void change_directory(const char *directory)
{
	if (directory == NULL || strcmp(directory, "") == 0)
	{
		directory = getenv("HOME");
	}
	if (chdir(directory) != 0)
	{
		perror("Failed to change directory");
	}
	else
	{
		set_environment_variable("PWD", directory);
	}
}

/**
 * simple_shell - A simple shell function.
 * Return: Void.
 */

void simple_shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];
	pid_t pid;
	int status;
	int i = 0;
	char *token;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		custom_fgets(command, MAX_COMMAND_LENGTH, stdin);
		command[custom_strcspn(command, "\n")] = 0;

		token = custom_strtok(command, " ");
		i = 0;

		while (token != NULL && i < MAX_ARGUMENTS - 1)
		{
			arguments[i] = token;
			token = custom_strtok(NULL, " ");
			i++;
		}
		arguments[i] = NULL;

		if (custom_strcmp(arguments[0], "exit") == 0)
		{
			if (arguments[1] != NULL)
			{
				int exit_status = custom_atoi(arguments[1]);

				exit(exit_status);
			}
			else
				exit(0);
		}
		if (custom_strcmp(arguments[0], "env") == 0)
		{
			print_environment();
			continue;
		}
		if (custom_strcmp(arguments[0], "setenv") == 0)
		{
			if (arguments[1] == NULL || arguments[2] == NULL)
			{
				perror("Usage: setenv VARIABLE VALUE");
				continue;
			}
			set_environment_variable(arguments[1], arguments[2]);
			continue;
		}
		if (strcmp(arguments[0], "unsetenv") == 0)
		{
			if (arguments[1] == NULL)
			{
				perror("Usage: unsetenv VARIABLE");
				continue;
			}
			unset_environment_variable(arguments[1]);
			continue;
		}
		if (strcmp(arguments[0], "cd") == 0)
		{
			change_directory(arguments[1]);
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("hsh: 1: command: not found");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(arguments[0], arguments, environ);
			perror("hsh: 1: command: not found");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}
