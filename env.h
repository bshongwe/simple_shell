#ifndef ENV_H
#define ENV_H

#include "dict.h"
#include <stdlib.h>

typedef dict_ env_t;

/* Prototypes */

	env_t *_env_to_dict(env_t **tailptr, char **env);
	env_t *env_to_dict(char **env);

#endif /* end of ENV_H file */
