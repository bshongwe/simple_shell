#ifndef PATH_H
#define PATH_H

/* Path Libraries */
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

char *search_path(info_t *info, list_t *path);

#endif /* PATH_H */
