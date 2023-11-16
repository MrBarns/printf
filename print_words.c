#include "main.h"

/**
 * print_char - prints a single character to stdout
 * @args: format arguments list
 *
 * Return: 1 if successful, -1 otherwise
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}


/**
 * print_str - prints a string of characters to stdout
 * @args: a list of format arguments.
 *
 * Return: number of characters printed, -1 otherwise
 */

int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int x;

	if (str == NULL)
		str = "(null)";

	for (x = 0; str[x] != '\0'; x++)
		;

	return (write(1, str, x));
}


/**
 * print_cent - prints '%' to stdout
 * @args: a list of format arguments.
 *
 * Return: 1 if successful, -1 otherwise
 */

int print_cent(va_list args)
{
	(void) args;

	return (write(1, "%%", 1));
}
