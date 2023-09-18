#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@ptr: pointer to the memory
 *@c: data to be set
 *@n: number of  bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *ptr, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		ptr[i] = c;
	return (ptr);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: char to check be checked
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _erratoi - converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers in string
 */
int _erratoi(char *str)
{
	int i = 0;
	unsigned long int num = 0;

	if (*str == '+')
		str++;
	for (i = 0;  str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num *= 10;
			num += (str[i] - '0');
			if (num > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (num);
}
/**
 * mfree - frees memory
 * @pp: string of strings
 */
void mfree(char **ptr)
{
	char **c = ptr;

	if (!ptr)
		return;
	while (*ptr)
		free(*ptr++);
	free(c);
}

