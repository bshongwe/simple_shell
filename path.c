#include "path.h"

/**
  * search_path - func search for dir with exec program
  * @info: arg passed
  * @path: arg passed
  * Return: dir string pointer
  */
char *search_path(info_t *info, list_t *path)
{
	char *pathname, *command = *info->tokens;
	struct stat sb;

	while (path)
	{
		if (*path->str == '\0')
			pathname = strjoin(NULL, "/", info->cwd, command);
		else
			pathname = strjoin(NULL, "/", path->str, command);
		if (stat(pathname, &sb) == 0)
		{
			if ((sb.st_mode & S_IFMT) != S_IFDIR)
				return (pathname);
		}
		free(pathname);
		path = path->next;
	}
	return (NULL);
}