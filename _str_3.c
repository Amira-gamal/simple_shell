#include "main.h"

/**
* _sncat - concatenates n bytes from a string to another
* @dest: destination string
* @src: source string
* @n: an input integer
* Return: a pointer to the resulting string dest
*/

char *_sncat(char *dest, char *src, int n)
{
	int i, x;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (x = 0; x < n &&  src[x] != '\0'; x++)
	{
		dest[i + x] = src[x];
	}
	dest[i + x] = '\0';
	return (dest);
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
* _sncpy - a function that copys the strings
* @dest: Destination of the pointer to the string
* @src: The source value
* @n: The copy limit
* Return: char value
*/

char *_sncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
		dest[i]	= src[i];
	while (i < n)
	{
		dest[i++] = '\0';
	}
	return (dest);
}
