#include "shell.h"
/**
 * my_strtok - function that extracts tokens from a string
 * @st: pointer to the string
 * @tk: pointer to the delimiter
 * Return: pointer to the next token or NULL if none
 */

char *my_strtok(char *st, const char *tk)
{
	static char *t, *s; 
	unsigned int a;

	if (st != NULL)
		s = st;
	t = s;

	if (t == NULL)
		return (NULL);
	for (a = 0; t[a] != '\0'; a++)
	{
		if (check_my_delim(t[a], tk) == 0)
			break;
	}

	if (s[a] == '\0' || s[a] == '#')
	{
		s = NULL;
		return (NULL);
	}

	t = s + a;
	s = t;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (check_my_delim(s[a], tk) == 1)
			break;
	}

	if (s[a] == '\0')
		s = NULL;
	else
	{
		s[a] = '\0';
		s = s + a + 1;

		if (*s == '\0')
			s = NULL;
	}
	return (t);
}
