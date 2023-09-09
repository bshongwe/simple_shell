#ifndef GETLINE_H
#define GETLINE_H

/* Struct defs */
#define GETLINE_TABLE_SIZE 127
#define GETLINE_BUFFER_SIZE 4096

/*Getline Libraries */
#include <unistd.h>
#include <stdlib.h>

/**
 * struct buf_table_node_s - struct for hash table input buffer
 * @fd: file descriptor
 * @buf: specific buffer reference
 * @next: specific consequent buffer in chain
 */
typedef struct buf_table_node_s
{
	int fd;
	struct buf_s buf;
	struct buf_table_node_s *next;
} buf_table_node_t;

/**
 * struct buf_s - struct for input buffer
 * @buffer: memory buffer allocation
 * @next: next value pointer
 * @remaining: remaining num values
 */
typedef struct buf_s
{
	char buffer[GETLINE_BUFFER_SIZE];
	char *next;
	size_t remaining;
} but_t;

/* Prototypes */
typedef buf_table_node_t *buf_table_t[GETLINE_TABLE_SIZE];
char *_getline(const int fd);

#endif /* _ end of GETLINE_H file */
