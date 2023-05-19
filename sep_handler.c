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
