#ifndef QUOTE_H
#define QUOTE_H

#include "string.h"
#include "ctype.h"
#include <stdlib.h>

/**
 * enum quote_state - quote state mnemonic struct
 * @QUOTE_NONE: in unquoted sequence of blanks
 * @QUOTE_WORD: in unquoted sequence of non-blanks
 * @QUOTE_DOUBLE: in double quotes
 * @QUOTE_SINGLE: in single quotes
 * @QUOTE_ESCAPE: after a back slash
 */
typedef enum quote_state
{
	QUOTE_NONE = 0X0,
	QUOTE_WORD = 0X1,
	QUOTE_DOUBLE = 0X2,
	QUOTE_SINGLE = 0X4,
	QUOTE_ESCAPE = 0X8
} quote_state_t;

typedef size_t (*quote_state_fp)(const char *, quotte_state_t *);

#endif /* end of QUOTE_H file */
