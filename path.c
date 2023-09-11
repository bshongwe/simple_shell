#include "path.h"

/**
 * search_path - func locates path forexcutable programme
 * @info: input arg
 * @path: input arg
 * Return: path directory pointer (Success), error (NULL)
 */
char *search_path(info_t *info, list_t *path)
{
	char *pathname, *command = *info->tokens;
	struct stat sb;

	while (path)
	{
		if (*path->str == '\0')
		{
			pathname = strjoin(NULL, "/", info->cwd, command);
		}
		else
		{
			pathname = strjoin(NULL, "/", path->str, command);
		}
		if (stat(pathname, &sb) == 0)
		{
			if ((sb.st_mode & S_IFMT) != S_IFDIR)
			{
				return (pathname);
			}
		}
		free(pathname);
		path = path->next;
	}
	return (NULL);
}
