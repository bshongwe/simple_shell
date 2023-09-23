#include "shell.h"

/**
 * print_a - func prints error message
 * @input: user input
 * @counter: shell loop count
 * @argv: init programme args
 * Return: void
 */
void print_a(char *input, int counter, char **argv)
{
	char *_a;

	PRINT(argv[0]);
	PRINT(": ");
	_a = _itoa(counter);
	PRINT(_a);
	free(_a);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 * error_file_msg - func prints custom file error msg
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Error Count
 */
void error_file_msg(char **argv, int c)
{
	char *_a = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(_a);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(_a);
}

/**
 *  _prerror_msg - func prints custom error msg
 * @argv: init programme args
 * @c: error counter
 * @cmd: parsed cmd strings array
 * Return: void
 */
void _prerror_msg(char **argv, int c, char **cmd)
{
	char *_a = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(_a);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": invalid number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(_a);
}

