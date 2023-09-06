#ifndef BUILTINS_H
#define BUILTINS_H

/* Public Libraries */
#include <unistd.h>
#include <stdlib.h>

/* Local Libraries */
#include "path.h"

/* Definitions */
#define EXIT_HELP "exit [STATUS]"
#define EXIT_DESC						\
	"Exit shell with a status of STATUS.\n\0"		\
	"If STATUS is omitted, exit status of last command.\0"	\
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

#endif /* end of BUILTINS_H file */
