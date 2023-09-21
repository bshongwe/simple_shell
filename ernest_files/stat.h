#ifndef _STAT_H_
#define _STAT_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *pathname, struct stat *statbuf);

#endif /* end of STAT_H file */