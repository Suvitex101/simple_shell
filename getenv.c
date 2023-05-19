#include "shell.h"

/**
 *my_getenv - Function to get eniron
 *@env: pointer to environ
 *Return: total environ or NULL
 */
char *my_getenv(char *env)
{
	size_t env_len, total_len;
	char *total;
	int a, b, c;

	env_len = my_strlen(env);
	for (a = 0; environ[a]; a++)
	{
		if (my_strncmp(env, environ[a], env_len) == 0)
		{
			total_len = my_strlen(environ[a]) - env_len;
			total = malloc(sizeof(char) * total_len);
			if (total == NULL)
			{
				free(total);
				perror("unable to alloc");
				return (NULL);
			}
			b = 0;
			for (c = env_len + 1; environ[a][c]; c++, b++)
			{
				total[b] = environ[a][c];
			}
			total[b] = '\0';
			return (total);
		}
	}
	return (NULL);
}
/**
 *create_cmd - Function to create cmd
 *@input: Pointer to cmd
 *@total: pointer to Directory
 *Return: path or NULL on failure
 */
char create_cmd(char *input, char *total)
{
	char *token;
	size_t run;

	run = my_strlen(total) + my_strlen(input) + 2;
	token = malloc(sizeof(char) * run);
	if (!token)
	{
		free(token);
		return (NULL);
	}
	memset(token, 0, run);

	token = my_strcat(token, total);
	token = my_strcat(token, "/");
	token = my_strcat(token, input);
	return (token);
}
