#include "main.h"

/**
 **_mem - fills memory
 *@x: pointer to memory
 *@by: byte to fill *s
 *@z: amount of bytes
 *Return: ------------
 */
char *_mem(char *x, char by, unsigned int z)
{
	unsigned int i;

	for (i = 0; i < z; i++)
		x[i] = by;
	return (x);
}

/**
 * _free_ - frees a string
 * @z: string
 */
void _free_(char **z)
{
	char **x = z;

	if (!z)
		return;
	while (*z)
		free(*z++);
	free(x);
}

/**
 * _realloc_ - reallocates memory
 * @x: pointer to previous malloc'ated block
 * @old_size: the byte size of the old
 * @new_size: the byte size of the new
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc_(void *x, unsigned int old_size, unsigned int new_size)
{
	char *z;

	if (!x)
		return (malloc(new_size));
	if (!new_size)
		return (free(x), NULL);
	if (new_size == old_size)
		return (x);

	z = malloc(new_size);
	if (!z)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		z[old_size] = ((char *)x)[old_size];
	free(x);
	return (z);
}
