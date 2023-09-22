#ifndef _CTYPE_H_
#define _CTYPE_H_

#include <stdlib.h>
#include <stdbool.h>

bool _isalnum(int c);
bool _isalpha(int c);
bool _isdigit(int c);
bool _isident(int c);
bool _isspace(int c);
bool _isquote(int c);
bool _isnumber(const char *s);

#endif /* end of CTYPE_H file */
