#include "main.h"

/**
 * *_add_nod - adds a node to the list
 * @h: address of pointer
 * @s: s field
 * @n: node index
 * Return: size of list
 */
list_t *_add_nod(list_t **h, const char *s, int n)
{
	list_t *new_h;

	if (!h)
		return (NULL);
	new_h = malloc(sizeof(list_t));
	if (!new_h)
		return (NULL);
	_memset((void *)new_h, 0, sizeof(list_t));
	new_h->num = n;
	if (s)
	{
		new_h->str = _strdup(s);
		if (!new_h->s)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *h;
	*h = new_h;
	return (new_h);
}

/**
 * _add_nod_end - adds node to end of list
 * @h: pointer adress to head
 * @s: str field of node
 * @n: node index
 * Return: size of list
 */
list_t *_add_nod_end(list_t **h, const char *s, int n)
{
	list_t *n_nod, *nod;

	if (!h)
		return (NULL);

	nod = *h;
	n_nod = malloc(sizeof(list_t));
	if (!n_nod)
		return (NULL);
	_memset((void *)n_nod, 0, sizeof(list_t));
	n_nod->n = n;
	if (s)
	{
		n_nod->s = _strdup(s);
		if (!n_nod->s)
		{
			free(n_nod);
			return (NULL);
		}
	}
	if (nod)
	{
		while (nod->next)
			nod = nod->next;
		nod->next = n_nod;
	}
	else
		*h = n_nod;
	return (n_nod);
}

/**
 * p_list_s - prints only the str element of a list_t
 * @x: first node
 * Return: size of list
 */
size_t p_list_s(const list_t *x)
{
	size_t i = 0;

	while (x)
	{
		_puts(x->str ? x->str : "(nil)");
		_puts("\n");
		x = x->next;
		i++;
	}
	return (i);
}

/**
 * del_nod_index - deletes node at given index
 * @h: address of pointer to first node
 * @ind: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int del_nod_index(list_t **h, unsigned int ind)
{
	list_t *nod, *pre_nod;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!ind)
	{
		nod = *h;
		*h = (*h)->next;
		free(nod->str);
		free(nod);
		return (1);
	}
	nod = *h;
	while (nod)
	{
		if (i == ind)
		{
			pre_nod->next = nod->next;
			free(nod->str);
			free(nod);
			return (1);
		}
		i++;
		prev_nod = nod;
		nod = nod->next;
	}
	return (0);
}

/**
 * f_list - frees all nodes of list
 * @h_p: address of pointer to head
 * Return: void
 */
void f_list(list_t **h_p)
{
	list_t *nod, *next_nod, *h;

	if (!h_p || !*h_p)
		return;
	h = *h_p;
	nod = h;
	while (nod)
	{
		next_nod = nod->next;
		free(nod->str);
		free(nod);
		nod = next_nod;
	}
	*h_p = NULL;
}

