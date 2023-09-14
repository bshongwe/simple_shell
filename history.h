#ifndef _HISTORY_H_
#define _HISTORY_H_

#include "list.h"
#include "types.h"

/**
  * struct history - shell command history
  * @head: history list head pointer
  * @filename: name of file history
  * @n: the number of entries in the history list
  */
struct history
{
	struct list *head;
	char *filename;
	size_t n;
};

#endif /* end of HISTORY_H file */
