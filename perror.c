#include "shell.h"

/**
 *my_perror - function to print custom error
 *@argv: Pointer to command arguments
 *@str: char line
 *@line: Command line
 */
void my_perror(char **argv, int str, char **line)
{
	char *error_msg = my_itoa(str);

	PRINTF(argv[0]);
	PRINTF(": ");
	PRINTF(error_msg);
	PRINTF(": ");
	PRINTF(line[0]);
	PRINTF(": Illegal number: ");
	PRINTF(line[1]);
	PRINTF("\n");
	free(error_msg);
}
/**
 *my_error - function to print custom error
 *@argv: Pointer to command arguments
 *@str: char line
 */
void my_error(char **argv, int str)
{
	char *error_msg = my_itoa(str);

	PRINTF(argv[0]);
	PRINTF(": ");
	PRINTF(": Can't open ");
	PRINTF(argv[1]);
	PRINTF("\n");
	free(error_msg);
}
