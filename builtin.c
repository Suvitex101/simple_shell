#include "shell.h"

/**
 *ch_dir - Function to change directory
 *@line: Command line
 *@c: command status
 *Return: 0 on success
 */
int ch_dir(char **line, __attribute__((unused))int c)
{
	int count = -1;
	char cwd[PATH_MAX];

	if (line[1] == NULL)
		count = chdir(getenv("HOME"));
	else if (my_strcmp(line[1], "-") == 0)
		count = chdir(getenv("OLDPWD"));
	else
		count = chdir(line[1]);

	if (count == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (count != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 *print_env - Function to print env
 *@line: Line command
 *@s: command status
 *Return: 0 always
 */
int print_env(__attribute__((unused)) char **line,
		__attribute__((unused)) int s)
{
	int val;
	size_t a;

	for (a = 0; environ[a] != NULL; a++)
	{
		val = my_strlen(environ[a]);
		write(1, environ[a], val);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
