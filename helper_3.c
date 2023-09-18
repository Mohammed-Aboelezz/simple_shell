#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @str: the input string
 * @delim: the delimeter string
 * Return: a pointer to an array of strings
 */

char **strtow(char *str, char *delim)
{
	int i, j, k, n, nwords = 0;
	char **c;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], delim) && (is_delim(str[i + 1], delim) || !str[i + 1]))
			nwords++;

	if (nwords == 0)
		return (NULL);
	c = malloc((1 + nwords) * sizeof(char *));
	if (!c)
		return (NULL);
	for (i = 0, j = 0; j < nwords; j++)
	{
		while (is_delim(str[i], delim))
			i++;
		k = 0;
		while (!is_delim(str[i + k], delim) && str[i + k])
			k++;
		c[j] = malloc((k + 1) * sizeof(char));
		if (!c[j])
		{
			for (k = 0; k < j; k++)
				free(c[k]);
			free(c);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			c[j][n] = str[i++];
		c[j][n] = 0;
	}
	c[j] = NULL;
	return (c);
}
