#include "shell.h"

/**
 * make_env - Creates env Variables
 * @line: Array to store
 */

void make_env(char **line)
{
	int a;

	for (a = 0; environ[a]; a++)
		line[a] = my_strdup(environ[a]);
	line[a] = NULL;
}

/**
 * env_mem_free - Frees env memory array
 * @input:  Array of Environment variables
 */

void env_mem_free(char **input)
{
	int a;

	for (a = 0; input[a]; a++)
	{
		free(input[a]);
	}
}
