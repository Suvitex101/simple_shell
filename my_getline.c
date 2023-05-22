#include "shell.h"

/**
*my_getline - function that reads input by user
* Return: the input by user on a buffer
*/

char *my_getline()
{
	int tmp, tmp2, buffsize = BUF_SIZ;
	char s = 0, *buffer, *buf;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (tmp = 0; s != EOF && s != '\n'; tmp++)
	{
		fflush(stdin);
		tmp2 = read(STDIN_FILENO, &s, 1);
		if (tmp2 == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[tmp] = s;
		if (buffer[0] == '\n')
			return (my_ent(buffer));
		if (tmp >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[tmp] = '\0';
	buf = my_space(buffer);
	free(buffer);
	my_hash(buf);
	return (buf);
}
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
