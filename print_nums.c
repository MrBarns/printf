#include "main.h"

/**
 * print_int - prints a signed decimal notation.
 * @args: list of specifier arguments.
 *
 * Return: number of characters printed, -1 otherwise
 */

int print_int(va_list args)
{
	int divisor = 1, num, printed = 0, is_min = 0;
	char digit;

	num = va_arg(args, int);
	if (num < 0)
	{
		if (num != -2147483648)
			num *= -1;
		else
		{
			is_min = 1;
			num -= 1;
		}
		printed += write(1, "-", 1);
	}

	while ((num / divisor) > 9)
	{
		if (((num / (divisor * 100)) > 0) &&
		    (divisor != 100000000))
			divisor *= 100;
		else
			divisor *= 10;
	}

	for (; divisor > 0; num %= divisor, divisor /= 10)
	{
		if ((divisor == 1) && is_min)
			digit = 8 + '0';
		else
			digit = (num / divisor) + '0';
		printed += write(1, &digit, 1);
	}

	return (printed);
}
