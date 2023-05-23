#include "shell.h"

/**
 *main - Shell main function
 *@argc: Count arguments
 *@argv: Argument array
 *Return: return command
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *run, **line, **parse;
	int value = 0, a, c = 1, s = 0;

	if (argv[1])
		file_reader(argv[1], argv);
	signal(SIGINT, handle_signal);
	while (c)
	{
		value++;
		if (isatty(STDIN_FILENO))
			prompt();
		run = my_getline();
		if (run[0] == '\0')
			continue;
		dis_history(run);
		parse = sep_handler(run);
		for (a = 0; parse[a] != NULL; a++)
		{
			line = run_cmd(parse[a]);
			if (my_strcmp(line[0], "exit") == 0)
			{
				free(parse);
				my_exit(line, run, argv, c, s);
			}
			else if (builtin_val(line) == 0)
			{
				s = process_builtin(line, s);
				free(line);
				continue;
			}
			else
				s = exec_cmd(line, run, c, argv);
			free(line);
		}
		free(run);
		free(parse);
		wait(&s);
	}
	return (s);
}
