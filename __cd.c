#include "builtins.h"

/**
 * __cd - func for changing directory
 * @info: args
 * Return: int status
 */
int __cd(info_t *info)
{
	char *dir = NULL, **args = info->tokens + 1;

	info->status = EXIT_SUCCESS;
	if (*args)
	{
		if (!_strcmp(*args, "-"))
		{
			dir = get_dict_val(info->env, "OLDPWD");
			if (!dir)
				dir = info->cwd;

			info->status = chdir(dir);
			if (!info->status)
			{
				write(STDOUT_FILENO, dir, _strlen(dir));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
		{
			dir = *args;
			info->status = chdir(dir);
		}
	}
	else
	{
		dir = get_dict_val(info->env, "HOME");
		if (dir)
			info->status = chdir(dir);
	}
	if (info->status != -1)
		__cd_success(info);
	else
		__cd_error(info, dir);

	return (info->status);
}

/**
 * __cd_error - func print error when __cd fails
 * @info: shell info
 * @dir: relevant directory
 * Return: void
 */
void __cd_error(info_t *info, char *dir)
{
	char *error = strjoin(NULL, " ", "Can not cd to", dir);

	perrorl_default(*info->argv, info->lineno, error, *info->tokens, NULL);

	info->status = 2;

	free(error);
}

/**
 * __cd_success - func updates env on succesful __cd
 * @info: shell info
 * Return: void
 */
void __cd_success(info_t *info)
{
	char *setenv_tokens[] = {"setenv", NULL, NULL, NULL};
	char **tokens = info->tokens;

	info->tokens = setenv_tokens;

	setenv_tokens[1] = "OLDPWD";
	setenv_tokens[2] = info->cwd;

	__setenv(info);

	free(info->cwd);
	info->cwd = getcwd(NULL, 0);

	setenv_tokens[1] = "PWD";
	setenv_tokens[2] = info->cwd;

	__setenv(info);

	info->tokens = tokens;

	info->status = EXIT_SUCCESS;
}
