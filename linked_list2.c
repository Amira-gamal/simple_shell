#include "main.h"

/**
 * list_len - returns then number of elements in a list.
 * @h: singly linked list.
 * Return: number of elements in the list.
 */

size_t list_len(const list_t *h)
{
	size_t n;

	for (n = 0; h != NULL; n++)
	{
		h = h->next;
	}
	return (n);
}

/**
 * list_str - returns an array of strings
 * @h: first node
 * Return: array of strings
 */
char **list_str(list_t *h)
{
	list_t *nod = h;
	size_t i = list_len(h), j;
	char **x;
	char *z;

	if (!h || !i)
		return (NULL);
	x = malloc(sizeof(char *) * (i + 1));
	if (!x)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		z = malloc(_strlen(node->Z) + 1);
		if (!z)
		{
			for (j = 0; j < i; j++)
				free(x[j]);
			free(x);
			return (NULL);
		}

		z = _strcpy(z, node->Z);
		x[i] = z;
	}
	x[i] = NULL;
	return (x);
}


/**
 * p_list - prints elements of list
 * @x: first node
 * Return: size of list
 */
size_t p_list(const list_t *x)
{
	size_t i = 0;

	while (x)
	{
		_puts(conve_num(x->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(x->str ? x->str : "(nil)");
		_puts("\n");
		x = x->next;
		i++;
	}
	return (i);
}

/**
 * starts_with - returns node w
 * @nod: list head
 * @pre: string
 * @x: the next character
 * Return: match node
 */
list_t *starts_with(list_t *nod, char *pre, char x)
{
	char *p = NULL;

	while (nod)
	{
		p = starts_with(nod->str, pre);
		if (p && ((x == -1) || (*p == x)))
			return (nod);
		nod = nod->next;
	}
	return (NULL);
}

/**
 * node_index - the index of a node
 * @h: list head
 * @nod: the node
 *
 * Return: index of node or -1
 */
ssize_t node_index(list_t *h, list_t *nod)
{
	size_t i = 0;

	while (h)
	{
		if (h == nod)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}

