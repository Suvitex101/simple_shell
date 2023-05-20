#include "shell.h"

/**
 * check_my_delim - function that checks if a character inputted
 * by user matches any character
 * @s: pointer to the character to check
 * @st: pointer to thr string of delimiters
 * Return: 1 on success, 0 on failure
 */

unsigned int check_my_delim(char s, const char *st)
{
	unsigned int a;

	for (a = 0; st[a] != '\0'; a++)
	{
		if (s == st[a])
			return (1);
	}
	return (0);
}

