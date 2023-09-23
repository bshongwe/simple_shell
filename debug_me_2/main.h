#ifndef MAIN_H
#define MAIN_H

/***LIBRARIES***/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

/***MACROS***/
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/***ENVIRONMENT***/

extern char **environ;

/***PROTOTYPES***/

char *custom_fgets(char *str, int size, FILE *stream);
int custom_strcmp(const char *s1, const char *s2);
size_t custom_strcspn(const char *str, const char *reject);
char *custom_strtok(char *str, const char *delim);
void print_environment(void);
void set_environment_variable(const char *variable, const char *value);
void unset_environment_variable(const char *variable);
void change_directory(const char *directory);
void simple_shell(void);
int custom_atoi(const char *str);
int main(void);
size_t custom_strlen(const char *str);

#endif /***END OF MAIN_H***/
