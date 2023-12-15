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
 * @ptr: pointer to previous malloc'ated block
 * @old_size: the byte size of the old
 * @new_size: the byte size of the new
 *
 * Return: pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min_size;
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	min_size = (old_size < new_size) ? old_size : new_size;
	for (i = 0; i < min_size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];
	free(ptr);
	return (new_ptr);
}
