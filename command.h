#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <stdlib.h>
#include "string.h"
#include "quote.h"
#include "types.h"
#include "tokens.h"

/**
 * enum cmdlist_sep_n - numeric vals for cmmd list separators
 * @SEMICOLON: ;
 * @AMPERSAND: &
 * @AND: &&
 * @OR: ||
 */
typedef enum cmdlist_sep_n
{
	SEMICOLON = 1,
	AMPERSAND = 2,
	AND       = 4,
	OR        = 8
} cmdlist_sep_n_t;

/**
 * struct cmdlist_sep - struct cmd list separator
 * @sep: cmd separator
 * @n: the corresponding numeric value
 */
typedef struct cmdlist_sep
{
	const char *sep;
	enum cmdlist_sep_n n;
} cmdlist_sep_t;

/**
 * struct cmdlist - struct for cmds linked list
 * @next: next cmd
 * @tree: cmd bin tree
 * @tokens: the tokens for each command in the tree
 */
struct cmdlist
{
	struct cmdlist *next;
	struct cmdtree *tree;
	char **tokens;
};

/**
 * struct cmdtree - func for cmds binary tree
 * @success: cmd to execute upon failure
 * @failure: cmd to execute upon success
 * @tokens: simple command with no separators
 * @sep: preceding list separator
 */
struct cmdtree
{
	struct cmdtree *success;
	struct cmdtree *failure;
	const char * const *tokens;
	struct cmdlist_sep sep;
};

size_t split_cmd(char *cmd);

cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count);
cmdlist_t *cmd_to_list(const char *cmd);

char **pop_cmd(cmdlist_t **headptr);
void free_cmdlist(cmdlist_t **headptr);
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd);
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index);

void free_cmdtree(cmdtree_t **rootptr);
cmdtree_t *cmd_to_tree(const char * const *tokens);

#endif /* end of _COMMAND_H_ file */