#ifndef PATH_H
#define PATH_H

// #define S_IFMT (S_IFBLK | S_IFCHR | S_IFIFO | S_IFREG | S_IFDIR | S_IFLNK)
// #define S_IFDIR 0040000

/* Path Libraries */
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "string.h"
#include "info.h"
#include "types.h"

char *search_path(info_t *info, list_t *path);

#endif /* end of PATH_H file */