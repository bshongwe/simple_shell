#ifndef _DICT_H_
#define _DICT_H_

#include <stdlib.h>
#include "types.h"
#include "string.h"

/**
  * struct dict - struct for singly linked list of key-value pairs
  * @key: var name
  * @val: var value
  * @next: next node pointer
  */
struct dict
{
	char *key;
	char *val;
	struct dict *next;
};

char *get_dict_val(dict_t *head, const char *key);
void free_dict(dict_t **headptr);
dict_t *get_dict_node(dict_t *head, const char *key);
dict_t *del_dict_node(dict_t **headptr, const char *key);
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val);

#endif /* end of DICT_H file */
