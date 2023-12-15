#include "main.h"

/**
 * **stow - splits a string into words
 * @s: input string
 * @d: delimeter string
 * Return: a pointer to an array
 */

char **stow(char *s, char *d)
{
	int i, j, k, m, numw = 0;
	char **n;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; s[i] != '\0'; i++)
		if (!is_delim(s[i], d) && (is_delim(s[i + 1], d) || !s[i + 1]))
			numw++;

	if (numw == 0)
		return (NULL);
	n = malloc((1 + numw) * sizeof(char *));
	if (!n)
		return (NULL);
	for (i = 0, j = 0; j < numw; j++)
	{
		while (is_delim(s[i], d))
			i++;
		k = 0;
		while (!is_delim(s[i + k], d) && s[i + k])
			k++;
		n[j] = malloc((k + 1) * sizeof(char));
		if (!n[j])
		{
			for (k = 0; k < j; k++)
				free(n[k]);
			free(n);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			n[j][m] = s[i++];
		n[j][m] = 0;
	}
	n[j] = NULL;
	return (n);
}

/**
 * **stow2 - splits a string into words
 * @s: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *s, char d)
{
	int i, j, k, m, numw = 0;
	char **n;

	if (s == NULL || s[0] == 0)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
		if ((s[i] != d && s[i + 1] == d) ||
		    (s[i] != d && !s[i + 1]) || s[i + 1] == d)
			numw++;
	if (numw == 0)
		return (NULL);
	n = malloc((1 + numw) * sizeof(char *));
	if (!n)
		return (NULL);
	for (i = 0, j = 0; j < numw; j++)
	{
		while (s[i] == d && s[i] != d)
			i++;
		k = 0;
		while (s[i + k] != d && s[i + k] && s[i + k] != d)
			k++;
		n[j] = malloc((k + 1) * sizeof(char));
		if (!n[j])
		{
			for (k = 0; k < j; k++)
				free(n[k]);
			free(n);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			n[j][m] = s[i++];
		n[j][m] = 0;
	}
	n[j] = NULL;
	return (n);
}
