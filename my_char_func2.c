#include "shell.h"
/**
 *my_strcpy - function that copy source
 *@buf: pointer to the destination
 *@sc: pointer to the source
 *Return: char copied
 */
char *my_strcpy(char *buf, char *sc)
{
	int a = 0;

	while (sc[a])
	{
		buf[a] = sc[a];
		a++;
	}
	buf[a] = '\0';
	return (buf);
}
/**
 *my_strcat - function that concat two string
 *@dest: pointer to the first string
 *@sr: pointer to the seecond string
 *Return: pointer to string
 */
char *my_strcat(char *dest, char *sr)
{
	char *ct = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*sr != '\0')
	{
		*dest = *sr;
		dest++;
		sr++;
	}
	*dest = '\0';
	return (ct);
}
/**
 * dis_num - display integers using _putchar function
 * @num: Unsigned integer
 */
void dis_num(unsigned int num)
{
	unsigned int a = num;

	if ((a / 10) > 0)
		dis_num(a / 10);

	_putchar(a % 10 + '0');
}

/**
 * dis_int - display integers using _putchar function
 * @num: Integer
 */

void dis_int(int num)
{
	unsigned int a = num;

	if (num < 0)
	{
		_putchar('-');
		a = -a;
	}
	if ((a / 10) > 0)
		dis_num(a / 10);

	_putchar(a % 10 + '0');
}
