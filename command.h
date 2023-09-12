#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
#include "string.h"
#include <stdlib.h>
#include "tokens.h"
#include "quote.h"

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
	SEMICOLON = 1,
	AMPERSAND = 2,
	AND       = 4,
	OR        = 8
} cmdlist_sep_n_t;

/* Prototypes entered below */
void free_cmdtree(cmdtree_t **rootptr);
void free_cmdlist(cmdlist_t **headptr);
char **pop_cmd(cmdlist_t **headptr);
size_t split_cmd(char *cmd);
cmdtree_t *cmd_to_tree(const char * const *tokens);
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index);
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count);
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd);
cmdlist_t *cmd_to_list(const char *cmd);

#endif /* end of COMMAND_H file */
