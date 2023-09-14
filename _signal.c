#include "hsh.h"

/**
  * _sigint -  func reprompts
  * @signal: signal passed
  * Return: void
  */
void _sigint(int signal __attribute__((unused)))
{
	fflush(STDIN_FILENO);
	write(STDERR_FILENO, "\n$ ", 3);
}
