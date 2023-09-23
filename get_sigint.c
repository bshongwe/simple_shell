#include "main.h"

/**
 * get_sigint - func handles crtl + c call in prompt
 * @sig: signal handler
 * Return: void
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
