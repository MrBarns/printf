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
	char spec[2];
	Mapper mappa[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_cent},
		{'d', print_int}, {'i', print_int}, {'\0', NULL}
	};

	if (format[x] == '\0')
		return (-1);

	for (c = 0; mappa[c].spec != '\0'; c++)
	{
		if (format[x] == mappa[c].spec)
			return (mappa[c].func(args));
	}

	spec[0] = '%';
	spec[1] = format[x];

	return (write(1, spec, 2));
}
