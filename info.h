#ifndef _INFO_H_
#define _INFO_H_

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#include "command.h"
#include "env.h"
#include "error.h"
#include "getline.h"
#include "history.h"
#include "list.h"
#include "string.h"
#include "tokens.h"
#include "types.h"
#include "alias.h"

extern char **environ;
typedef int pid_t;

/**
  * struct info - shell state
  * @interactive: arguments passed
  * @argc: args passed
  * @argv: args passed
  * @file: args passed
  * @fileno: args passed
  * @status: args passed
  * @line: args passed
  * @lineno: args passed
  * @tokens: args passed
  * @pid: args passed
  * @cwd: args passed
  * @exe: args passed
  * @env: args passed
  * @path: args passed
  * @aliases: args passed
  * @history: args passed
  * @commands: args passed
  */
struct info
{
	int interactive;
	int argc;
	char **argv;
	char *file;
	int fileno;
	int status;
	char *line;
	size_t lineno;
	char **tokens;
	pid_t pid;
	char *cwd;
	char *exe;
	env_t *env;
	list_t *path;
	alias_t *aliases;
	history_t *history;
	cmdlist_t *commands;
};

int free_info(info_t *info);
info_t *init_info(int argc, char **argv);

#endif /* end of _INFO_H_ file */