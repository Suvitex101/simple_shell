#include "shell.h"

/**
 *run_cmd - Funtion to parse stdin command
 *@line: string parse to command
 *Return: command
 */
char **run_cmd(char *line)
{
	char **inputs, *input;
	int a, buf = BUF_SIZ;

	if (line[0] == ' ' && line[my_strlen(line)] == ' ')
		exit(0);
	if (!line)
		return (NULL);
	inputs = malloc(sizeof(char *) * buf);
	if (inputs == NULL)
	{
		free(inputs);
		perror("hsh");
		return (NULL);
	}
	input = my_strtok(line, "\n\t\r\a ");
	for (a = 0; input; a++)
	{
		inputs[a] = input;
		input = my_strtok(NULL, "\n\t\r\a ");
	}
	inputs[a] = NULL;
	return (inputs);
}
