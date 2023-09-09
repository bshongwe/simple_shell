#ifndef HISTORY_H
#define HISTORY_H

/* types header */
/* list header */

/**
 * struct history - struct for shell cmd history
 * @head: history list head pointer
 * @filename: file signature in history
 * @n: history list entry count
 */
struct history
{
	struct list *head;
	char *filename;
	size_t n;
};

#endif /* end of HISTORY_H file */
