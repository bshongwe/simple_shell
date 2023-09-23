#ifndef _SHELL_H_
#define _SHELL_H_

/* Macros */
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/* Std Libs */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sys Libs */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Other Libs */
#include <linux/limits.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

/* Main helpers */
int _putchar(char c);
extern char **environ;

/* Built-in Cmds Struct */
/**
 * struct _builtin - struct for built-in commands
 * @command: - built-in cmd
 * @function: - custom func pointers for cmds similar to built-in cmds
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

/* __cmd_exec_stdin.c */
int check_cmd(char **cmd, char *input, int c, char **argv);
void sig_to_handle(int sig);

/* __cmd_exec.c  */
int echo_bltn(char **cmd, int st);
void print_number_int(int st);
void print_echo(char **cmd);
int pr_env(__attribute__((unused)) char **cmd,
	    __attribute__((unused)) int st);
int history_pr(__attribute__((unused))char **c,
		__attribute__((unused)) int st);
int __cd(char **cmd, __attribute__((unused))int st);

/* __cmd_parser.c */
char **parse_stdn_cmd(char *input);

/* __delim.c */
unsigned int check_delim(char c, const char *str);

/* __env.c */
void env_var(char **env_a);
void free_env(char **env);

/* __error.c */
void print_a(char *input, int counter, char **argv);
void error_file_msg(char **argv, int c);
void _prerror_msg(char **argv, int c, char **cmd);

/* __mem.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **cmd, char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_cbyte_arr(void *a, int el, unsigned int len);
void *fill_an_array(void *a, int el, unsigned int len);

/* __path.c */
int path_exec_cmd(char **cmd);
char *build_cmd(char *token, char *value);
char *_getenv(char *name_en_var);
char *build(char *token, char *value);

/* __print.c */
void print_num_int(int n);
void print_num_un(unsigned int n);
int print_btn_echo(char **cmd);
void print_number(unsigned int n);

/* __prompt.c */
void prompt_std(void);

/* __rcd_history.c */
int history_user_file(char *input);

/* __sep.c */
char **sep_cmd_std(char *input);

/* __string_handlers_1.c */
void _puts(char *str);
int _atoi(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);

/* __string_handlers_2.c */
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/* __string_handlers_3.c */
char *_itoa(unsigned int n);
int _strcmp(char *s1, char *s2);
void arr_rev(char *arr, int len);
int intlen(int num);
int _isalpha(int c);
void path_cmd(char **cmd);
void print_error(char *cmd, int c, char **argv);

/* _getline.c */
void hashtag_handler(char *buff);
char *enter(char *string);
char *space(char *str);
char *_getline();

/* _strtok.c */
char *_strtok(char *str, const char *delim);

/* bltn_cmds.c */
int pop_bltn(char **cmd, int st);
int check_bltn(char **cmd);
void exit_bltn(char **cmd, char *input, char **argv, int c, int stat);
void _prerror(char **argv, int c, char **cmd);

/* bltn_help_0.c */
int pr_help(char **cmd, __attribute__((unused))int st);
void help_unsetenv(void);
void help_all(void);

/* bltn_help_1.c */
void help_alias(void);
void help_cd(void);
void help_exit(void);

/* bltn_help_2.c */
void help_help(void);
void help_env(void);
void help_setenv(void);

/* file_args.c */
void file_read(char *file, char **argv);
void file_treat(char *line, int count, FILE *fp, char **argv);
void exit_bltn_file(char **cmd, char *line, FILE *fd);
void error_file(char **argv, int count);
void treat_file(char *line, int count, FILE *fp, char **argv);
char **parse_cmd(char *line);
int handle_builtin(char **cmd, int stat);
int check_builtin(char **cmd);

/* shell.h*/
void read_file(char *file, char **argv);
void prompt(void);
void history(char *input);
char **separator(char *input);
void exit_bul(char **cmd, char *input, char **argv, int count, int stat);

#endif /* end of SHELL_H file */
