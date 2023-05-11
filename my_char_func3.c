#include "shell.h"

/**
 *my_strdup - function that double a string
 *@st: pointer to the string
 *Return: duplicate
 */
char *my_strdup(char *st)
{
	size_t count;
	size_t a;
	char *st2;

	count = my_strlen(st);
	st2 = malloc(sizeof(char) * (count + 1));

	if (st2 == NULL)
		return (NULL);
	for (a = 0; a <= count; a++)
	{
		st2[a] = st[a];
	}
	return (st2);
}
/**
 *my_strncmp - function that compare two strings
 *@str1: pointer to the first string
 *@str2: pointer to the second string
 *@num: value of char compared
 *Return: 0 on success
 */
int my_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t a;

	if (!str1)
		return (-1);
	for (a = 0; a < num && str2[a]; a++)
	{
		if (str1[a] != str2[a])
			return (1);
	}
	return (0);
}
/**
 *my_strchr - function that check char in a string
 *@str: pointer to the string
 *@s: char in the string
 *Return: pointer to the string
 */
char *my_strchr(char *str, char s)
{

	for (; *str != '\0'; str++)
	{
		if (*str == s)
		{
			return (str);
		}
	}
	return (NULL);
}
