#ifndef INFO_H
#define INFO_H

#include <unistd.h>
#include "env.h"
#include "getline.h"
#include "string.h"
#include "types.h"
#include "command.h"
#include "alias.h"
#include "error.h"

extern char **environ;

/**
 * struct info - shell state
 * @fileno: args passed
 * @line: args passed
 * @env: args passed
 * @path: args passed
 * @aliases: args passed
 * @commands: args passed
 */
struct info
{
	char *file;
	int *fileno;
	char *line;
	size_t lineno;
	charr **tokens;
	env_t *env;
	cmdlist_t *commands;
};


#endif /* end of INFO_H file */
