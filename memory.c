#include "shell.h"

/**
 *my_calloc - memory allocator
 *@value: size of memory
 *Return: pointer
 */
void *my_calloc(unsigned int value)
{
	unsigned int a;
	char *tmp;

	if (value == 0)
		return (NULL);
	tmp = malloc(value);
	if (!tmp)
		return (NULL);
	for (a = 0; a < value; a++)
	{
		tmp[a] = '\0';
	}
	return (tmp);
}
/**
 *my_realloc - memory allocator
 *@point: pointer value
 *@old_s: current memory size
 *@new_s: new memory size
 *Return: pointer to the new memory allocated
 */
void *my_realloc(void *point, unsigned int old_s, unsigned int new_s)
{
	void *output;

	if (new_s == old_s)
		return (point);
	if (new_s == 0 && point)
	{
		free(point);
		return (NULL);
	}
	output = malloc(new_s);
	if (!output)
	{
		free(output);
		return (NULL);
	}
	if (!point)
	{
		mem_arr(output, '\0', new_s);
		free(point);
	}
	else
	{
		my_memcpy(output, point, old_s);
		free(point);
	}
	return (output);
}
