#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Format
 * @i: arguments.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int current = *i + 1;
	int precision = -1;

	if (format[current] != '.')
		return (precision);

	precision = 0;

	current = current + 1;
	while (format[current] != '\0')
	{
		if (is_digit(format[current]))
		{
			precision = precision * 10;
			precision += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
		current++;
	}

	*i = current - 1;

	return (precision);
}
