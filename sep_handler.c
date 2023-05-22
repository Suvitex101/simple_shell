#include "shell.h"

/**
 *sep_handler - Function to handle seperator
 *@cmd: command to run
 *Return: all command
 */
char **sep_handler(char *cmd)
{
	char **inputs;
	char *input;
	int a;
	int buff = BUF_SIZ;

	if (cmd[0] == ' ' && cmd[my_strlen(cmd)] == ' ')
		exit(0);
	if (!cmd)
		return (NULL);
	inputs = malloc(sizeof(char *) * buff);
	if (inputs == NULL)
	{
		free(inputs);
		perror("hsh");
		return (NULL);
	}
	input = my_strtok(cmd, ";&");
	for (a = 0; input; a++)
	{
		inputs[a] = input;
		input = my_strtok(NULL, ";&");
	}
	inputs[a] = NULL;
	return (inputs);
}
/**
 *dis_history - Function to keep users history
 *@line: Command line
 *Return: 1 on success
 */
int dis_history(char *line)
{
	int run = 0;
	char *fname = ".display_history";
	ssize_t rd, wt;

	if (fname == NULL)
		return (-1);
	rd = open(fname, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (rd < 0)
		return (-1);
	if (line != NULL)
	{
		while (line[run])
			run++;
		wt = write(rd, line, run);
		if (wt < 0)
			return (-1);
	}
	return (1);
}
