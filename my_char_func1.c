#include "shell.h"

/**
 *my_intlen - function to get the lenght of int
 *@n: value of the lenght
 *Return: lenght
 */
int my_intlen(int n)
{
	int count = 0;

	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
/**
 *my_arr_rev - function to reverse array
 *@ar: pointer to the array
 *@m: lenght of the array
 */
void my_arr_rev(char *ar, int m)
{
	char buf;
	int a;

	for (a = 0; a < (m / 2); a++)
	{
		buf = ar[a];
		ar[a] = ar[(m - 1) - a];
		ar[(m - 1) - a] = buf;
	}
}
/**
 *my_itoa - a function that convert int to char
 *@num: the int to convert
 *Return: pointer to char
 */
char *my_itoa(unsigned int num)
{
	int count = 0;
	int a = 0;
	char *str;

	count = my_intlen(num);
	str = malloc(count + 2);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	while (num / 10)
	{
		str[a] = (num % 10) + '0';
		num /= 10;
		a++;
	}
	str[a] = (num % 10) + '0';
	my_arr_rev(str, count);
	str[a + 1] = '\0';
	return (str);
}
/**
 *my_isalpha - function that check for alphabet
 *@s: string to be checked
 *Return: 1 or 0
 */
int my_isalpha(int s)
{
	if (((s >= 97) && (s <= 122)) || ((s >= 65) && (s <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 *my_strcmp - function that compare string
 *@str1: first string
 *@str2: second string
 *Return: always 0
 */
int my_strcmp(char *str1, char *str2)
{
	int a, count1, count2, tmp = 0;

	count1 = my_strlen(str1);
	count2 = my_strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (count1 != count2)
		return (1);
	for (a = 0; str1[a]; a++)
	{
		if (str1[a] != str2[a])
		{
			tmp = str1[a] - str2[a];
			break;
		}
		else
			continue;
	}
	return (tmp);
}
