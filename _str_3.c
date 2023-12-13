#include "main.h"

/**
 **_sncat - concatenates
 *@x: the first string
 *@y: the second string
 *@z: the amount of bytes
 *Return: the result
 */
char *_sncat(char *x, char *y, int z)
{
	int i, j;
	char *s = x;

	i = 0;
	j = 0;
	while (x[i] != '\0')
		i++;
	while (y[j] != '\0' && j < z)
	{
		x[i] = y[j];
		i++;
		j++;
	}
	if (j < z)
		x[i] = '\0';
	return (s);
}

/**
 **_schr - locates the character
 *@s: the string
 *@c: the character
 *Return: (s) a pointer
 */
char *_schr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}

/**
 **_sncpy - copies a string
 *@d: string
 *@x: string
 *@y: the amount
 *Return: the result
 */
char *_sncpy(char *d, char *x, int y)
{
	int i, j;
	char *s = d;

	i = 0;
	while (x[i] != '\0' && i < y - 1)
	{
		d[i] = x[i];
		i++;
	}
	if (i < y)
	{
		j = i;
		while (j < y)
		{
			d[j] = '\0';
			j++;
		}
	}
	return (s);
}
