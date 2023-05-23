#include "shell.h"

/**
 *my_exit - Functionn to Exit shell
 *@line: Command line
 *@run: Command from User
 *@argv: Arguments
 *@n: Count number of exec
 *@s: Exit
 */
void my_exit(char **line, char *run, char **argv, int n, int s)
{
	int check, a = 0;

	if (line[1] == NULL)
	{
		free(run);
		free(line);
		exit(s);
	}
	while (line[1][a])
	{
		if (my_isalpha(line[1][a++]) != 0)
		{
			my_perror(argv, n, line);
			free(run);
			free(line);
			exit(2);
		}
		else
		{
			check = my_atoi(line[1]);
			if (check == 2)
			{
				my_perror(argv, n, line);
				free(run);
				free(line);
				exit(check);
			}
			free(run);
			free(line);
			exit(check);
		}
	}
}
