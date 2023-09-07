#ifndef BUILTINS_H
#define BUILTINS_H

/* Public Libraries */
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/* Local Libraries */
#include "path.h"
#include "env.h"

/* Definitions */
#define EXIT_HELP "exit [STATUS]"
#define EXIT_DESC						\
	"Exit shell with a status of STATUS.\n\0"		\
	"If STATUS is omitted, exit status of last command.\0"	\
	"\0"

#define ENV_HELP "env"
#define ENV_DESC								\
	"Print environment.\0"							\
	"\0"

#define SETENV_HELP "setenv [NAME [VALUE]]"
#define SETENV_DESC								\
	"Set environment variable NAME to VALUE.\n\0"				\
	"If NAME is omitted, shell execution environment is displayed.\0"	\
	"If VALUE is omitted, value of NAME is set to empty string.\0"		\
	"\0"

#define UNSETENV_HELP "unsetenv NAME"
#define UNSET ENV_DESC								\
	"Remove variable NAME from environment.\0"				\
	"\0"

#define CD_HELP "cd [DIR]"
#define CD_DESC									\
	"Change current working directory to DIR.\n\0"				\
	"If DIR is omitted, rollback to default of value of HOME variable. \0"	\
	"If DIR is -, current directory assumes previous value.\0"		\
	"\0"

/* Builtin Struct */
typedef int (*builtin_fp)(info_t *);

/**
 * struct builtin - struct builtin commands
 * @name: name of command
 * @f: invoked to call function
 * @help: usage of command
 * @desc: command description
 */
struct builtin
{
	const char *name;
	const char help;
	const char *desc;
	builtin_fp f;
};

/* Main Prototypes */
const struct builtin *get_builtins(void);
const struct builtin *get_builtin(const char *name);
/* Add-ins */
int __exit(info_t *info);
int __setenv(info_t *info);
int __unsetenv(info_t *info);
int __env(info_t *info);
int __cd(info_t *info);

#endif /* end of BUILTINS_H file */
