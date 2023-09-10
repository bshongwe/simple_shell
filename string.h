#ifndef STRING_H
#define STRING_H

/* LIBS */
#include <stdarg.h>
#include <stdlib.h>

unsigned int atou(char *s);
static void _num_to_str(char **buf, size_t n);
char *num_to_str(size_t n);
ssize_t _strlen(const char *str);
ssize_t _strnlen(const char *str, size_t n);
ssize_t _memchr(const void *src, unsigned char chr, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
void *_memdup(const void *src, size_t n);
void *_memset(void *dest, unsigned char chr, size_t n);
ssize_t _strchr(const char *str, char chr);
ssize_t _strnchr(const char *str, char chr, size_t n);
char *strjoin(size_t *n, const char *sep, const char *pre, const char *suf);
char *strjoina(size_t *n, const char *sep, const char **array);
char *strjoinl(size_t *n, const char *sep, ...);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);
char *_strndup(const char *str, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, size_t n);

#endif /* end of STRING_H file */
