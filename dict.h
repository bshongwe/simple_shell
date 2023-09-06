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

#endif /* end of DICT_H file */
