#include "shell.h"

/**
 * my_ent - function that takes a string to a new line
 * @str: pointer to the string to be taken to a new line
 * Return: Empty string
 */

char *my_ent(char *str)
{
	free(str);
	return ("\0");
}

/**
 * my_space - function that removes whitespaces in string
 * upon calling
 * @st: string to be modified
 * Return: Returns the modified string
 */

char *my_space(char *st)
{
	int a, b = 0;
	char *tmp;

	tmp = malloc(sizeof(char) * (my_strlen(st) + 1));

	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}

	for (a = 0; st[a] == ' '; a++)
		;
	for (; st[a + 1] != '\0'; a++)
	{
		tmp[b] = st[a];
		b++;
	}
	tmp[b] = '\0';

	if (tmp[0] == '\0' || tmp[0] == '#')
	{
		free(tmp);
		return ("\0");
	}
	return (tmp);
}

/**
 * my_hash - function that removes everything after a '#'
 * @tmp: pointer to the input buffer
 * Return: nothing
 */

void my_hash(char *tmp)
{
	int a;

	for (a = 0; tmp[a] != '\0'; a++)
	{
		if (tmp[a] == '#' && tmp[a - 1] == ' ' && tmp[a + 1] == ' ')
		{
			tmp[a] = '\0';
		}
	}
}
