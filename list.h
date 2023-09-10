#ifndef LIST_H
#define LIST_H

/**
 * struct list - struct for singly linked list
 * @str: dynam-alloced string
 * @next: next node pointer
 */
struct list
{
	char *str;
	struct list *next;
}

void free_list(list_t **headptr);

#endif /* end of LIST_H file */
