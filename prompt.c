#include "shell.h"

/**
 *handle_signal - Function to handle ctrl C
 *@check: parse in line
 */
void handle_signal(int check)
{
	if (check == SIGINT)
	{
		PRINTF("\n($) ");
	}
}

/**
 *prompt - function to display prompt
 */
void prompt(void)
{
	PRINTF("($) ");
}
