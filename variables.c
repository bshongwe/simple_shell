#include "varibles.h"

/* Code has syntax errors. Looks more like python than it does C */

/**
 * _get_variables - Get variables to quckily execute commands.
 *
 *
 * Return: The varibles value.
 */

_get_varibles(command, varible)
{
	stucts i = 0;

	while (i != NULL)
	{
		if (varible != NULL && varible == stuct[i])
		{
			/*need to store command? e.g. (echo)*/
			return (stuctfp);
		}
		i++;
	}
	return (NULL);
}

/**
 * _$?_variable_func - Get variables to quckily execute commands.
 *
 *
 * Return: The varibles value.
 */

_$?_varible_func(_get_varibles())
{
	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: command S?\n", 18);
	}
	if ((_get_varibles()) == NULL && av[2] != $?)
	{
		perror(Command not found);
	}

	/*store the previous commands return value and return it*/
	return $? = /*0 if prev cmd success -1 if prev commnd failed*/
}

/**
 * _$$_variable_func - Get variables to quckily execute commands.
 *
 *
 * Return: The varibles value.
 */

_$$_varible_func()
{
	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: command S?\n", 18);
	}
	if ((_get_varibles()) == NULL && av[2] != $$)
	{
		perror(Command not found);
	}

	int id = getpid

	return (write(STDOUT_FILENO, id, 1)); /*not sure how to do this*/
}

/**
 * _$PATH_varible_func - Get variables to quckily execute commands.
 *
 *
 * Return: The varibles value.
 */

_$PATH_varible_func()
{	
	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: command S?\n", 18);
	}

	if ((_get_varibles()) == NULL && av[2] != $PATH)
	{
		perror(Command not found);
	}
	/*return the path*/
}
