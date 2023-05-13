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
	int i;
	int x = 0;
	int y = -1;
	int z = 0;

	for (i = 0; st[i] != '\0'; i++)
	{
		if (st[i] == '-')
			y = y * -1;
		if (st[i] >= '0' && st[i] <= '9')
		{
			x = x * 10;
			x -= (st[i] - '0');
			z = 1;
		}
		else if (z == 1)
			break;
	}
	x = y * x;
	return (x);
}
