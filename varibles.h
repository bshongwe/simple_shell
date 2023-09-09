#ifndef VARIABLES_H
#define VARIABLES_H

/*LIBRARIES*/

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>

/*PROTOTYPES*/

	_get_variables();
	_$?_variable_func();
	_$$_variable_func();
	_$PATH_variable_func();

/*STRUCTS*/

	typedef struct;
	{
		$?; fptr = _$?_variable;
		$$;
		$PATH;

	} Varibles;

#endif
