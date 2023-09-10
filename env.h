#ifndef ENV_H
#define ENV_H

#include "dict.h"
#include <stdlib.h>

typedef dict_ env_t;

/* Prototypes */
char **dict_to_env(env_t *head);
env_t *env_to_dict(char **env);
env_t *_env_to_dict(env_t **tailptr, char **env);

#endif /* end of ENV_H file */
