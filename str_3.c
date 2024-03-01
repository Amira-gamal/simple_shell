#include "main.h"

/**
* _strncpy - a function that copys the strings
* @dest: Destination of the pointer to the string
* @src: The source value
* @n: The copy limit
* Return: char value
*/

char *_strncpy(char *dest, char *src, int n)
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

/**
* _strncat - concatenates n bytes from a string to another
* @dest: destination string
* @src: source string
* @n: an input integer
* Return: a pointer to the resulting string dest
*/

char *_strncat(char *dest, char *src, int n)
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
* _strchr - function that locates a character in a string
*@s: first value -char
*@c: second value - char
* Return: char with result
*/

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return ('\0');
}

