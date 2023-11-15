#include "main.h"


/**
 * _printf - writes output to stdout according to a format
 * @format: string specifying format for output
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, x, spec_result;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			spec_result = handle_specs(format, ++x, args);
			if (spec_result < 0)
				return (-1);
			printed_chars += spec_result;
		}
		else
		{
			write(1, &format[x], 1);
			printed_chars++;
		}
	}

	va_end(args);
	return (printed_chars);
}
