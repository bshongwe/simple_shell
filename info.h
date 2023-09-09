#ifndef INFO_H
#define INFO_H

#include <unistd.h>
#include <stdlib.h>
#include "env.h"
#include "getline.h"
#include "string.h"
#include "types.h"
#include "command.h"
#include "alias.h"
#include "error.h"
#include "tokens.h"
#include "history.h"
#include "list.h"

extern char **environ;

/**
 * struct info - shell state
 * @fileno: args passed
 * @file: args passed
 * @line: args passed
 * @env: args passed
 * @path: args passed
 * @aliases: args passed
 * @commands: args passed
 * @line: args passed
 * @lineno: args passed
 * @tokens: args passed
 * @cwd: args passed
 * @argc: args passed
 * @argv: args passed
 * @exe: args passed
 * @status: args passed
 * @history: args passed
 * @interactive: args passed
 * @pid: args passed
 */
struct info
{
	char *file;
	int *fileno;
	int argc;
	int status;
	char *line;
	char *cwd;
	char **argv;
	size_t lineno;
	char *exe
	char **tokens;
	int interactive;
	env_t *env;
	list_t *path;
	history_t *history;
	alias_t *aliases;
	cmdlist_t *commands;
};

int free_info(info_t *info);
info_t *intit_info(int argc, char **argv);


#endif /* end of INFO_H file */
