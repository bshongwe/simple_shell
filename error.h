#ifndef ERROR_H
#define ERROR_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...);
void perrorl(const char *msg, ...);

#endif/* end of  ERROR_H file */
