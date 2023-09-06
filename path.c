#include "path.h"

/**
 * search_path - func locates path forexcutable programme
 * @info: input arg
 * @path: input arg
 * Return: path directory pointer (Success), error (NULL)
 */
char *search_path(info_t *info, list_t *path)
{
	char *path_name, *cmd = *info->tokens;
	struct stat sb;

	while (path)
	{
		if (*path->str == '\0')
		{
			path_name = strjoin(NULL, "/", info->cwd, cmd);
		}
		else
		{
			path_name = strjoin(NULL, "/", path->str, cmd);
		}
		if (stat(path_name, &sb) == 0)
		{
			if ((sb.st_mode & S_IFMT) != S_IFDIR)
			{
				return (path_name);
			}
		}
		free(path_name);
		path = path->next;
	}
	return (NULL);
}
