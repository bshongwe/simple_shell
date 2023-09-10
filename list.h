#ifndef LIST_H
#define LIST_H

/* ~LIBRARIES~ */
#include <stdlib.h>
#include "string.h"
#include "types.h"

/* ~STRUCTS~ */
/**
 * struct list - Singly linked list.
 * @str: A dynamically-allocated string.
 * @next: A pointer to the next node.
 */
struct list
{
	char *str;
	struct list *next;
};

/* ~PROTOTYPES~ */

list_t *str_to_list(const char *str, char delim);
list_t *_str_to_list(list_t **tailptr, const char *str, char delim);
list_t *add_node(list_t **headptr, const char *str);
list_t *add_node_end(list_t **headptr, const char *str);
void free_list(list_t **headptr);

#endif /* ~LIST_H~ */
