#ifndef TOKENS_H
#define TOKENS_H

/* Libraries */
#include <stdlib.h>

/* Main Prototypes */
char **tokenize(const char *str);
void free_tokens(char ***tokens);

/* Midddleware */
size_t count_tokens(const char *str);
size_t count_tokens_no_quote(const char *str);

/* Additional Mem-ware */
char **tokenize_noquote(const char *str);
char **arrjoin(char **arr1, char **arr2);
char **arrdup(char **arr);

#endif /* end of  TOKENS_H */
