#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
#include "string.h"
#include <stdlib.h>

/**
 * struct cmdlist - func for link list cmds
 * @next: next cmd
 * @tree: cmd bin tree
 * @tokens: specific cmd token iD
 */
struct cmdlist
{
	char **tokens;
	struct cmdlist *next;
	struct cmdtree *tree;
};

/**
 * struct cmdlist_sep -struct for cmd list sep
 * @sep: cmd sep
 * @n: specific num val
 */
typedef struct cmdlist_sep
{
	const char *sep;
	enum cmdlist_sep_n n;
} cmdlist_sep_t;

/**
 * struct cmdtree - cmds bin tree
 * @success: cmd to exec when prev cmd fails
 * @failure: cmd to exec when prev cmd fails
 * @tokens: cmd with no seps
 * @sep: next list sep
 */
struct cmdtree
{
	const char * const *tokens;
	struct cmdlist_sep sep;
	struct cmdtree *success;
	struct cmdtree *failure;
};

/**
 * enum cmdlist_sep_n - command list seperators num vals
 * @SEMICOLON: ;
 * @AMPERSAND: &
 * @AND: &&
 * @OR: ||
 */
typedef enum cmdlist_sep_n /* need to assign values below */
{
	SEMICOLON =,
	AMPERSAND =,
	AND       =,
	OR        =
} cmdlist_sep_n_t;

/* Prototypes entered below */


#endif /* end of COMMAND_H file */
