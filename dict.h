#ifndef DICT_H
#define DICT_H

#include <stdlib.h>

/**
 * struct dict - struct for key-val pair singly linked list
 * @key: name var
 * @val: var value
 * @next: next node pointer
 */
struct dict
{
	char *key;
	char *val;
	struct dict *next;
};

/* Prototypes */
dict_t *get_dict_node(dict_t *head, const char *key);
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val);
dict_t *del_dict_node(dict_t **headptr, const char *key);
void free_dict(dict_t **headptr);
char *get_dict_val(dic_t *head, const char *key);

#endif /* end of DICT_H file */
