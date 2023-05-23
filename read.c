#include "shell.h"

/**
 * file_reader - Function to read command from file
 * @f: File
 * @argv: Arguments
 */
void file_reader(char *f, char **argv)
{
	FILE *rd;
	char *run = NULL;
	size_t len = 0;
	int c = 0;

	rd = fopen(f, "r");
	if (!rd)
	{
		my_error(argv, c);
		exit(127);
	}
	while ((getline(&run, &len, rd)) != -1)
	{
		c++;
		run_file(run, c, rd, argv);
	}
	if (run != NULL)
		free(run);
	fclose(rd);
	exit(0);
}

/**
 * run_file - Function to handle cmd and exec
 * @cmd: pointer to command
 * @c: Error
 * @fl: File descriptor
 * @argv: Command line arguments
 */

void run_file(char *cmd, int c, FILE *fl, char **argv)
{
	char **run;
	int check = 0;

	run = run_cmd(cmd);
	if (my_strncmp(run[0], "exit", 4) == 0)
		exit_file(run, cmd, fl);
	else if (builtin_val(run) == 0)
	{
		check = process_builtin(run, check);
		free(run);
	}
	else
	{
		check = exec_cmd(run, cmd, c, argv);
		free(run);
	}
}

/**
 * exit_file - Exit for file input
 * @input: input from a file
 * @cmd: Parsed command
 * @fl: File Descriptor
 */

void exit_file(char **cmd, char *input, FILE *fl)
{
	int check;
	int a = 0;

	if (cmd[a] == NULL)
	{
		free(input);
		free(cmd);
		fclose(fl);
		exit(errno);
	}
	while (cmd[1][a])
	{
		if (my_isalpha(cmd[1][a++]) < 0)
			perror("Illegal number");
	}
	check = my_atoi(cmd[1]);
	free(input);
	free(cmd);
	fclose(fl);
	exit(check);
}
