#include "shell.h"

/**
 *my_strlen - function to count string lenght
 *@str: string pointer
 *Return: lenght
 */

int my_strlen(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		continue;
	}
	return (a);
}
/**
 *_putchar - writes the character c to stdout
 *@c: The character to print
 *
 *Return: On success 1.
 *On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *my_strncpy - function to copy a string
 *@dst: pointer to a string
 *@sc: pointer to second string
 *@n: integer
 *Return: string copied
 */
char *my_strncpy(char *dst, char *sc, int n)
{
	int a = 0;

	while (a < n && *(sc + a))
	{
		*(dst + a) = *(sc + a);
		a++;
	}
	while (a < n)
	{
		*(dst + a) = '\0';
		a++;
	}
	return (dst);
}
/**
 *my_puts - function to print a string
 *@stri: pointer to the string
 *Return: void
 */
void my_puts(char *stri)
{
	int a;

	for (a = 0; stri[a] != '\0'; a++)
	{
		_putchar(stri[a]);
	}
	_putchar('\n');
}
/**
 *my_atoi - function to convert string to int
 *@st: pointer to a string
 *Return: the int value
 */
int my_atoi(char *st)
{
	int i, a;
	int b, x;

	i = b = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	a = i;
	while ((s[a] >= '0') && (s[a] <= '9'))
	{
		b = (b * 10) + x * ((s[a]) - '0');
		a++;
	}
	return (b);
}
