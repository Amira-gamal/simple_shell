#include "main.h"

/**
 * _eatoi - converts a string to an integer
 * @str: the converted string
 * Return: 0 if no numbers in string
 */
int _eatoi(char *str)
{
	int i = 0;
	unsigned long int r = 0;

	if (*str == '+')
		str++;  /* TODO: why does this make main return 255? */
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			r *= 10;
			r += (str[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (r);
}

/**
 * p_error - prints an error message
 * @inf: the parameter
 * @es: string containing error
 * Return: 0 if no numbers in string
 */
void p_error(inf_t *inf, char *es)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(es);
}

/**
 * p_deci - function prints a decimal
 * @n: the input
 * @f: the filedescriptor to write
 * Return: number of characters printed
 */
int p_deci(int n, int f)
{
	int (*__putchar)(char) = _putchar;
	int i, c = 0;
	unsigned int _abs_, current;

	if (f == STDERR_FILENO)
		__putchar = _eputchar;
	if (n < 0)
	{
		_abs_ = -n;
		__putchar('-');
		c++;
	}
	else
		_abs_ = n;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			c++;
		}
		current %= i;
	}
	__putchar('0' + current);
	c++;
	return (c);
}

/**
 * conve_num - converter function, a clone of itoa
 * @i: number
 * @b: base
 * @f: argument flags
 * Return: string
 */
char *conve_num(long int i, int b, int f)
{
	static char *arr;
	static char buff[50];
	char s = 0;
	char *p;
	unsigned long n = i;

	if (!(f & CONVERT_UNSIGNED) && i < 0)
	{
		n = -i;
		s = '-';

	}
	arr = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do	{
		*--p = arr[n % b];
		n /= b;
	} while (n != 0);

	if (s)
		*--p = s;
	return (p);
}

/**
 * rm_com - replaces first instance of '#' with '\0'
 * @b: address of the string
 * Return: Always 0;
 */
void rm_com(char *b)
{
	int i = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '#' && (!i || b[i - 1] == ' '))
		{
			b[i] = '\0';
			break;
		}
	}
	i++;
}
