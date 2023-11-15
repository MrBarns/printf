#include "main.h"


/**
 * handle_specs - parses and implements format specifiers
 *
 * @format: format specifier string
 * @x: position of specifier in string
 * @args: list of format arguments
 *
 * Return: number of characters printed in implementation
 * -1 in case of failure.
 */

int handle_specs(const char *format, int x, va_list args)
{
	int c;
	Mapper mappa[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_cent},
		{'\0', NULL}
	};

	for (c = 0; mappa[c].spec != '\0'; c++)
	{
		if (format[x] == mappa[c].spec)
			return (mappa[c].func(args));
	}

	return (-1);
}
