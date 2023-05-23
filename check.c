#include "shell.h"

/**
 *builtin_val - Check Builtin cmd
 *@line: command line
 *Return: O on Success and 1 on failure
 */
int builtin_val(char **line)
{
	builtincmd functions[] = {
		{"cd", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int a = 0;

	if (*line == NULL)
		return (-1);
	while ((functions + a)->cmd)
	{
		if (my_strcmp(line[0], (functions + a)->cmd) == 0)
			return (0);
		a++;
	}
	return (-1);
}
/**
 *process_builtin - Handle builtin
 *@line: Command line
 *@c: Command status
 *Return: 0 on success and 1 on failure
 */
int process_builtin(char **line, int c)
{
	builtincmd run_builtin[] = {
		{"cd", ch_dir},
		{"env", print_env},
		{"echo", echo_handler},
		{"history", echo_history},
		{NULL, NULL}
	};
	int a = 0;

	while ((run_builtin + a)->cmd)
	{

		if (my_strcmp(line[0], (run_builtin + a)->cmd) == 0)
		{
			return ((run_builtin + a)->func(line, c));
		}
		a++;
	}
	return (-1);
}
