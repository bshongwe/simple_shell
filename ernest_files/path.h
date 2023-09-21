#ifndef _PATH_H_
#define _PATH_H_

/* Path Libraries */
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "string.h"
#include "info.h"
#include "types.h"

char *search_path(info_t *info, list_t *path);

#endif /* end of PATH_H file */